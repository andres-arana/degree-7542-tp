#include "rocket.h"
#include "../move/rocketposmovepoint.h"
#include "../move/rockettargetmovepoint.h"
#include "../connect/rocketposconnectionpoint.h"

using namespace game::core;
using namespace game::core::affectors;
using namespace game::design::connect;
using namespace game::design::elements;
using namespace game::design::move;

namespace {
	const double stdBodyRadius = 10;
	const double stdHeadRadius = 5;
	const double stdBodyMass = 1;
	const double stdHeadMass = 0.5;
	const double stdBodyHeaderDistance = 5;
	const double stdSpringStrength = 4500;
	const double stdTargetDistance = 25;
	const double stdK = 4500;
}

Rocket::Rocket(bool isEditable, double strength, double decayTime, const Vector2d &startPosition) :
	Element(isEditable),
	strength(strength),
	decayTime(decayTime),
	affector(NULL) {

	setPosition(startPosition);
	setTarget(Vector2d(startPosition.getX() + stdTargetDistance, startPosition.getY()));
	if (isEditable) {
		// Agregar move points
		movePoints.push_back(new RocketPosMovePoint(*this));
		movePoints.push_back(new RocketTargetMovePoint(*this));
	}
	connectionPoints.push_back(new RocketPosConnectionPoint(*this));
}

Vector2d Rocket::getValidTarget(const Vector2d &potentialTarget) {
	Vector2d vectorAux = potentialTarget - position;
	double length = vectorAux.norm();
	vectorAux.normalize();
	if (length == 0) {
		vectorAux.setX(1);
		vectorAux.setY(0);
	}
	if (length != stdTargetDistance) {
		return position + (vectorAux * stdTargetDistance);
	}
	return potentialTarget;
}

void Rocket::setPosition(const Vector2d &value) {
	position = value;
	modifiedSignal();
}

const Vector2d &Rocket::getPosition() const {
	return position;
}

void Rocket::setTarget(const Vector2d &value) {
	target = getValidTarget(value);
	modifiedSignal();
}

const Vector2d &Rocket::getTarget() const {
	return target;
}

double Rocket::getBodyRadius() const {
	return stdBodyRadius;
}

double Rocket::getStrength() const {
	return strength;
}

double Rocket::getDecayTime() const {
	return decayTime;
}

bool Rocket::containsPoint(const core::Vector2d &vector) const {
	if (this->isErased()) return false;
	return position.distanceTo(vector) <= getBodyRadius();
}

void Rocket::buildParticlesAndSprings() {
	Vector2d axis = target - position;
	axis.normalize();

	particles.push_back(new Particle(stdBodyMass, stdBodyRadius, position));
	particles.push_back(new Particle(stdHeadMass, stdHeadRadius, position + axis * (stdBodyRadius + stdHeadRadius + stdBodyHeaderDistance)));

	springs.push_back(new Spring(*particles[0], *particles[1], stdSpringStrength));

	if (getBaseConnectionPoint().isConnected()) {
		ConnectionPoint::particle_list connectionParticles = getBaseConnectionPoint().getConnectionParticles();
		for (ConnectionPoint::particle_list::iterator it = connectionParticles.begin(); it != connectionParticles.end(); ++it) {
			springs.push_back(new Spring(*particles[0], **it, stdK));
		}
	}

	if (affector) {
		delete affector;
	}
	affector = new DecayingForceAffector(strength, decayTime, *particles[1]);
	particles[0]->registerAffector(affector);
}

Rocket::~Rocket() {
	if (affector) {
		delete affector;
	}
}

ConnectionPoint &Rocket::getBaseConnectionPoint() {
	return *connectionPoints[0];
}
