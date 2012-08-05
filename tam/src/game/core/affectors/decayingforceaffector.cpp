#include "decayingforceaffector.h"
#include "../particle.h"

using namespace game::core;
using namespace game::core::affectors;

DecayingForceAffector::DecayingForceAffector(double initialForceMagnitude, double decayTime, const Particle &axisDestination)
	: axisDestination(axisDestination), initialForceMagnitude(initialForceMagnitude), decayTime(decayTime), active(false) {

}

Vector2d DecayingForceAffector::GetAffectingForce(const Particle &particle) {
	if (!active) {
		timeDelta.updateTimeMilestone();
		active = true;
	}

	double time = timeDelta.getDeltaFromTimeMilestone();

	if (time < decayTime) {
		double currentForceMagnitude = (initialForceMagnitude * (-time / decayTime)) + initialForceMagnitude;
		Vector2d forceAxis = axisDestination.getPosition() - particle.getPosition();
		forceAxis.normalize();
		return forceAxis * currentForceMagnitude;
	} else {
		return Vector2d();
	}

}
