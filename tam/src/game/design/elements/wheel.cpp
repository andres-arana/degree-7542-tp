#include "wheel.h"
#include "../../core/vector2d.h"
#include "utils/math.h"
#include "../connect/radiusconnectionpoint.h"
#include "../connect/centerconnectionpoint.h"
#include <cmath>

using namespace common::utils;
using namespace game::core;
using namespace game::core::affectors;
using namespace game::design::elements;
using namespace game::design::connect;

namespace {
	const double stdK = 4500;
	const double stdMassRadius = 6.5;
	const double stdMassValue = 0.33;
	const double stdMaxMassDistance = 15;

	double calculateAngle(int requiredMasses) {
		return (Math::PI * 2.0) / static_cast<double>(requiredMasses);
	}

	double calculateVertexDistance(double radius, int requiredMasses) {
		return 2.0 * radius * sin(calculateAngle(requiredMasses) / 2.0);
	}

	int calculateRequiredMasses(double radius) {
		int requiredMasses = 4;
		double vertexDistance = calculateVertexDistance(radius, requiredMasses);
		while (vertexDistance > stdMaxMassDistance) {
			requiredMasses++;
			vertexDistance = calculateVertexDistance(radius, requiredMasses);
		}
		return requiredMasses;
	}
}

Wheel::Wheel(bool isEditable, double minRadius, double maxRadius, double torqueMagnitude, double decayTime) :
	CenterRadiusElement(isEditable, minRadius, maxRadius),
	torqueMagnitude(torqueMagnitude),
	decayTime(decayTime),
	affector(NULL) {

	connectionPoints.push_back(new RadiusConnectionPoint(*this));
	connectionPoints.push_back(new CenterConnectionPoint(*this));
}

double Wheel::getTorqueMagnitude() const {
	return torqueMagnitude;
}

double Wheel::getDecayTime() const {
	return decayTime;
}

void Wheel::buildParticlesAndSprings() {
	int requiredMasses = calculateRequiredMasses(getRadius());
	double initialAngle = Vector2d(1.0, 0.0).angleTo(getRadiusPosition() - getPosition());
	double angle = -calculateAngle(requiredMasses);

	particles.push_back(new Particle(stdMassValue, stdMassRadius, getPosition()));
	if (affector) {
		delete affector;
	}
	affector = new TorqueForceAffector(torqueMagnitude, decayTime, *particles[0]);

	for (int i = 0; i < requiredMasses; i++) {
		Vector2d position = (Vector2d(cos(initialAngle + i * angle), sin(initialAngle + i * angle)) * getRadius()) + getPosition();
		particles.push_back(new Particle(stdMassValue, stdMassRadius, position));
	}

	for (size_t i = 1; i < particles.size() - 1; i++) {
		springs.push_back(new Spring(*particles[i], *particles[i + 1], stdK));
	}

	springs.push_back(new Spring(*particles[particles.size() - 1], *particles[1], stdK));

	for (size_t i = 1; i < particles.size(); i++) {
		springs.push_back(new Spring(*particles[i], *particles[0], stdK));
		particles[i]->registerAffector(affector);
	}

	if (getRadiusConnectionPoint().isConnected()) {
		ConnectionPoint::particle_list connectionParticles = getRadiusConnectionPoint().getConnectionParticles();
		for (ConnectionPoint::particle_list::iterator it = connectionParticles.begin(); it != connectionParticles.end(); ++it) {
			springs.push_back(new Spring(*particles[1], **it, stdK));
		}
	}

	if (getCenterConnectionPoint().isConnected()) {
		ConnectionPoint::particle_list connectionParticles = getCenterConnectionPoint().getConnectionParticles();
		for (ConnectionPoint::particle_list::iterator it = connectionParticles.begin(); it != connectionParticles.end(); ++it) {
			springs.push_back(new Spring(*particles[0], **it, stdK));
		}
	}
}

ConnectionPoint  &Wheel::getRadiusConnectionPoint() {
	return *connectionPoints[0];
}

ConnectionPoint  &Wheel::getCenterConnectionPoint() {
	return *connectionPoints[1];
}

Wheel::~Wheel() {
	if (affector) {
		delete affector;
	}
}
