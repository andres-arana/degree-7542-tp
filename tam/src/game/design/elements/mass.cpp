#include "mass.h"
#include "../connect/centerconnectionpoint.h"

using namespace game::core;
using namespace game::design::connect;
using namespace game::design::elements;

namespace {
	const double stdK = 4500;
}

Mass::Mass(bool isEditable, double minRadius, double maxRadius, double mass) :
	CenterRadiusElement(isEditable, minRadius, maxRadius),
	mass(mass) {

	connectionPoints.push_back(new CenterConnectionPoint(*this));
}

double Mass::getMass() const {
	return mass;
}

void Mass::buildParticlesAndSprings() {
	particles.push_back(new Particle(mass, getRadius(), getPosition()));

	if (getCenterConnectionPoint().isConnected()) {
		ConnectionPoint::particle_list connectionParticles = getCenterConnectionPoint().getConnectionParticles();
		for (ConnectionPoint::particle_list::iterator it = connectionParticles.begin(); it != connectionParticles.end(); ++it) {
			springs.push_back(new Spring(*particles[0], **it, stdK));
		}
	}
}

ConnectionPoint &Mass::getCenterConnectionPoint() {
	return *connectionPoints[0];
}
