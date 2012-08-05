#include "fixedpoint.h"
#include "../connect/centerconnectionpoint.h"

using namespace game::core;
using namespace game::design::connect;
using namespace game::design::elements;

namespace {
	const double stdMass = 10;
	const double stdK = 4500;
}

FixedPoint::FixedPoint(bool isEditable, double minRadius, double maxRadius) :
		CenterRadiusElement(isEditable, minRadius, maxRadius) {

	connectionPoints.push_back(new CenterConnectionPoint(*this));
}

void FixedPoint::buildParticlesAndSprings() {
	Particle *p = new Particle(stdMass, getRadius(), getPosition());
	p->setFixed(true);
	p->setCollisionable(false);
	particles.push_back(p);

	if (getCenterConnectionPoint().isConnected()) {
		ConnectionPoint::particle_list connectionParticles = getCenterConnectionPoint().getConnectionParticles();
		for (ConnectionPoint::particle_list::iterator it = connectionParticles.begin(); it != connectionParticles.end(); ++it) {
			springs.push_back(new Spring(*particles[0], **it, stdK));
		}
	}
}

ConnectionPoint &FixedPoint::getCenterConnectionPoint() {
	return *connectionPoints[0];
}
