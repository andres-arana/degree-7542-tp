#include "particle.h"
#include <algorithm>
#include <numeric>

using namespace std;
using namespace game::core;
using namespace game::core::affectors;

namespace {
	class ForceAccumulationFunctor {
	public:
		ForceAccumulationFunctor(const Particle& particle)
			: particle(particle) {

		}

		Vector2d operator()(const Vector2d &previous_value, ForceAffector *affector) {
			return previous_value + affector->GetAffectingForce(particle);
		}
	private:
		const Particle &particle;
	};
}

Particle::Particle(double mass, double radius, const Vector2d &position, double collisionElasticRatio)
	: mass(mass), radius(radius), collisionElasticRatio(collisionElasticRatio), position(position), fixed(false), collisionable(true) {

}

double Particle::getMass() const {
	return mass;
}

double Particle::getRadius() const {
	return radius;
}

const Vector2d &Particle::getPosition() const {
	return position;
}

Vector2d &Particle::getUpdateablePosition() {
	return position;
}

void Particle::setPosition(const Vector2d &value) {
	position = value;
}

const Vector2d &Particle::getSpeed() const {
	return speed;
}

Vector2d &Particle::getUpdateableSpeed() {
	return speed;
}

void Particle::setSpeed(const Vector2d &value) {
	speed = value;
}

Vector2d Particle::getAcceleration() const {
	Vector2d force = accumulate(affectors.begin(), affectors.end(), Vector2d(), ForceAccumulationFunctor(*this));
	return force * (1 / mass);
}

bool Particle::isFixed() const {
	return fixed;
}

void Particle::setFixed(bool value) {
	fixed = value;
}

bool Particle::isCollisionable() const {
	return collisionable;
}

void Particle::setCollisionable(bool value) {
	collisionable = value;
}

double Particle::getCollisionElasticRatio() const {
	return collisionElasticRatio;
}

void Particle::setCollisionElasticRatio(double value) {
	collisionElasticRatio = value;
}

void Particle::registerAffector(ForceAffector *affector) {
	affectors.push_back(affector);
}

void Particle::unregisterAffector(ForceAffector *affector) {
	affectors_list::iterator it = find(affectors.begin(), affectors.end(), affector);

	if (it != affectors.end()) {
		affectors.erase(it);
	}
}

bool Particle::collidesWith(const Particle& other) {
	if (!isCollisionable() || !other.isCollisionable()) {
		return false;
	}

	return getPosition().distanceTo(other.getPosition()) < getRadius() + other.getRadius();
}
