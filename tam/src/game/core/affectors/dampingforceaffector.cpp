#include "dampingforceaffector.h"
#include "../particle.h"

using namespace game::core;
using namespace game::core::affectors;

DampingForceAffector::DampingForceAffector(double damping)
	: damping(-damping) {

}

Vector2d DampingForceAffector::GetAffectingForce(const Particle& particle) {
	return particle.getSpeed() * damping;
}
