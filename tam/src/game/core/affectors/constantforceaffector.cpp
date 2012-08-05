#include "constantforceaffector.h"
#include "../particle.h"

using namespace game::core;
using namespace game::core::affectors;

ConstantForceAffector::ConstantForceAffector(const Vector2d& force)
	: force(force) {

}

Vector2d ConstantForceAffector::GetAffectingForce(const Particle& particle) {
	return force;
}



