#include "gravityforceaffector.h"
#include "../particle.h"

using namespace game::core;
using namespace game::core::affectors;

GravityForceAffector::GravityForceAffector(const Vector2d& gravity)
	: gravity(gravity) {

}

Vector2d GravityForceAffector::GetAffectingForce(const Particle& particle) {
	return gravity * particle.getMass();
}
