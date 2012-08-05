#include "physicsengine.h"
#include "utils/collections.h"
#include <algorithm>
#include <cmath>

using namespace std;
using namespace game::core;
using namespace game::core::affectors;

typedef std::vector<Particle *> particle_pointer_list;
typedef std::vector<Particle> particle_list;
typedef std::vector<affectors::ForceAffector *> affector_pointer_list;
typedef std::vector<affectors::ForceAffector> affector_list;

namespace {
	const double stdMaxDeltaT = 0.007;

	typedef std::vector<Vector2d> vector_list;

	void generateSystemStateCopy(particle_pointer_list &source, vector_list &destination_pos, vector_list &destination_spd) {
		typedef particle_pointer_list::iterator pp_iter;
		for (pp_iter it = source.begin(); it != source.end(); it++) {
			destination_pos.push_back((*it)->getPosition());
			destination_spd.push_back((*it)->getSpeed());
		}
	}

	void updateSystemState(particle_pointer_list &destination, vector_list &source_pos, vector_list &source_spd) {
		for (size_t i = 0; i < destination.size(); i++) {
			destination[i]->setPosition(source_pos[i]);
			destination[i]->setSpeed(source_spd[i]);
		}
	}

	void updateStepVariable(Vector2d &variable, Vector2d &original, Vector2d &k, double delta) {
		//variable = original + (k * delta);
		variable = k;
		variable *= delta;
		variable += original;
	}

	void updateFinalVariable(Vector2d &variable, Vector2d &original, Vector2d &k1, Vector2d &k2, Vector2d &k3, Vector2d &k4, double delta) {
		//varialbe = original + (k1 + k4 + 2 * (k2 + k3)) * delta / 6;
		variable = k2;
		variable += k3;
		variable *= 2;
		variable += k1;
		variable += k4;
		variable *= (delta / 6);
		variable += original;
	}

	void handleCollision(Particle &first, Particle &second) {
		Vector2d axis = first.getPosition() - second.getPosition();
		double distance = axis.norm();
		axis.normalize();

		double v1i = Vector2d::innerProduct(axis, first.getSpeed());
		double v2i = Vector2d::innerProduct(axis, second.getSpeed());

		double m1 = first.getMass();
		double m2 = second.getMass();

		double e = first.getCollisionElasticRatio() + second.getCollisionElasticRatio();

		double v1f = (m1 * v1i + m2 * (v2i + e * (v2i - v1i))) / (m1 + m2);
		double v2f = v1f - e * (v2i - v1i);

		double required_distance = first.getRadius() + second.getRadius();
		double delta = required_distance - distance;

		if (!first.isFixed()) {
			first.setSpeed(first.getSpeed() + (axis * (v1f - v1i)));
			first.setPosition(first.getPosition() + (axis * (delta / 2)));
		}

		if (!second.isFixed()) {
			second.setSpeed(second.getSpeed() + (axis * (v2f - v2i)));
			second.setPosition(second.getPosition() - (axis * (delta / 2)));
		}
	}

	void handleRK4Step(particle_pointer_list &fixedParticles, particle_pointer_list &dynamicParticles, particle_pointer_list &collisionableParticles, double delta_t) {
		vector_list upd_p_pos;
		vector_list upd_p_spd;
		vector_list ori_p_pos;
		vector_list ori_p_spd;

		generateSystemStateCopy(dynamicParticles, upd_p_pos, upd_p_spd);
		generateSystemStateCopy(dynamicParticles, ori_p_pos, ori_p_spd);

		// Proceso el k1 del estado de las particulas
		vector_list k1_pos;
		vector_list k1_spd;
		for (size_t i = 0; i < dynamicParticles.size(); i++) {
			k1_pos.push_back(dynamicParticles[i]->getSpeed());
			k1_spd.push_back(dynamicParticles[i]->getAcceleration());
			updateStepVariable(upd_p_pos[i], ori_p_pos[i], k1_pos[i], delta_t / 2.0);
			updateStepVariable(upd_p_spd[i], ori_p_spd[i], k1_spd[i], delta_t / 2.0);
		}

		// Updateo las particulas para los afectores en k2
		updateSystemState(dynamicParticles, upd_p_pos, upd_p_spd);

		// Proceso el k2 del estado de las particulas
		vector_list k2_pos;
		vector_list k2_spd;
		for (size_t i = 0; i < dynamicParticles.size(); i++) {
			k2_pos.push_back(dynamicParticles[i]->getSpeed());
			k2_spd.push_back(dynamicParticles[i]->getAcceleration());
			updateStepVariable(upd_p_pos[i], ori_p_pos[i], k2_pos[i], delta_t / 2.0);
			updateStepVariable(upd_p_spd[i], ori_p_spd[i], k2_spd[i], delta_t / 2.0);
		}

		// Updateo las particulas para los afectores en k3
		updateSystemState(dynamicParticles, upd_p_pos, upd_p_spd);

		// Proceso el k3 del estado de las particulas
		vector_list k3_pos;
		vector_list k3_spd;
		for (size_t i = 0; i < dynamicParticles.size(); i++) {
			k3_pos.push_back(dynamicParticles[i]->getSpeed());
			k3_spd.push_back(dynamicParticles[i]->getAcceleration());
			updateStepVariable(upd_p_pos[i], ori_p_pos[i], k3_pos[i], delta_t);
			updateStepVariable(upd_p_spd[i], ori_p_spd[i], k3_spd[i], delta_t);
		}

		// Updateo las particulas para los afectores en k4
		updateSystemState(dynamicParticles, upd_p_pos, upd_p_spd);

		// Proceso el k4 del estado de las particulas
		vector_list k4_pos;
		vector_list k4_spd;
		for (size_t i = 0; i < dynamicParticles.size(); i++) {
			k4_pos.push_back(dynamicParticles[i]->getSpeed());
			k4_spd.push_back(dynamicParticles[i]->getAcceleration());
		}

		// Actualizo las posiciones y velocidades de las particulas
		// reales
		for (size_t i = 0; i < dynamicParticles.size(); i++) {
			updateFinalVariable(dynamicParticles[i]->getUpdateablePosition(), ori_p_pos[i], k1_pos[i], k2_pos[i], k3_pos[i], k4_pos[i], delta_t);
			updateFinalVariable(dynamicParticles[i]->getUpdateableSpeed(), ori_p_spd[i], k1_spd[i], k2_spd[i], k3_spd[i], k4_spd[i], delta_t);
		}

		// Chequeo colisiones
		for (size_t i = 0; i < collisionableParticles.size(); i++) {
			for (size_t j = 0; j < i; j++) {
				if (collisionableParticles[i]->collidesWith(*collisionableParticles[j])) {
					handleCollision(*collisionableParticles[i], *collisionableParticles[j]);
				}
			}

			typedef vector<Particle *>::iterator iterator;
			for (iterator iter = fixedParticles.begin(); iter != fixedParticles.end(); ++iter) {
				if (collisionableParticles[i]->collidesWith(**iter)) {
					handleCollision(*collisionableParticles[i], **iter);
				}
			}
		}
	}
}

PhysicsEngine::PhysicsEngine()
	: remainderStep(0) {

}

void PhysicsEngine::registerParticle(Particle *particle) {
	if (particle->isFixed()) {
		fixedParticles.push_back(particle);
	} else {
		dynamicParticles.push_back(particle);
		if (particle->isCollisionable()) {
			collisionableParticles.push_back(particle);
		} else {
			noncollisionableParticles.push_back(particle);
		}
	}

	if (!particle->isFixed()) {
		typedef affector_pointer_list::iterator affector_iter;
		for (affector_iter it = affectors.begin(); it != affectors.end(); it++) {
			particle->registerAffector(*it);
		}
	}
}

void PhysicsEngine::addSystemWideAffector(ForceAffector *affector) {
	affectors.push_back(affector);

	typedef particle_pointer_list::iterator iterator;
	for (iterator it = dynamicParticles.begin(); it != dynamicParticles.end(); it++) {
		(*it)->registerAffector(affector);
	}
}

void PhysicsEngine::doTimeStep() {
	double delta_t = timeDelta.getDeltaFromTimeMilestone() + remainderStep;
	timeDelta.updateTimeMilestone();

	double steps = floor(delta_t / stdMaxDeltaT);

	for (int i = 0; i < steps; i++) {
		handleRK4Step(fixedParticles, dynamicParticles, collisionableParticles, stdMaxDeltaT);
	}

	remainderStep = delta_t - (steps * stdMaxDeltaT);
}

PhysicsEngine::~PhysicsEngine() {
	common::utils::DeleteAndClearElements(affectors);
}
