#include "springforceaffector.h"
#include "../particle.h"

using namespace game::core;
using namespace game::core::affectors;

SpringForceAffector::SpringForceAffector(Particle &springEnd, double k, double relaxedDistance)
	: springEnd(springEnd), k(k), relaxedDistance(relaxedDistance) {

}

Vector2d SpringForceAffector::GetAffectingForce(const Particle& particle) {
	Vector2d axis = springEnd.getPosition() - particle.getPosition();
	double distance = axis.norm();
	axis.normalize();

	return axis * (k * (distance - relaxedDistance));

}
