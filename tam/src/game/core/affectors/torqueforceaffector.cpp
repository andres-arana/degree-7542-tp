#include "torqueforceaffector.h"
#include "utils/math.h"
#include <cmath>

using namespace game::core::affectors;
using namespace game::core;
using namespace common::utils;
using namespace std;

TorqueForceAffector::TorqueForceAffector(double initialTorqueMagnitude, double decayTime, const Particle &centerParticle)
	: centerParticle(centerParticle), initialTorqueMagnitude(initialTorqueMagnitude), decayTime(decayTime), active(false) {

}

Vector2d TorqueForceAffector::GetAffectingForce(const Particle &particle) {
	if (!active) {
		timeDelta.updateTimeMilestone();
		active = true;
	}

	double time = timeDelta.getDeltaFromTimeMilestone();

	if (time < decayTime) {
		double currentTorqueMagnitude = (initialTorqueMagnitude * (-time / decayTime)) + initialTorqueMagnitude;
		Vector2d axis = particle.getPosition() - centerParticle.getPosition();
		double angleToNormalAxis = -(Math::PI / 2 - axis.angleTo(Vector2d(0, 1)));
		Vector2d normalAxis = Vector2d(sin(angleToNormalAxis), cos(angleToNormalAxis));
		Vector2d force = normalAxis * (currentTorqueMagnitude / axis.norm());
		return force;
	} else {
		return Vector2d();
	}
}
