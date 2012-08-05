#include "stringelement.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::connect;

namespace {
	const double stdK = 1500;
	const double stdMassRadius = 3.5;
	const double stdMassValue = 0.1;
	const double stdMaxMassDistance = 9;
	const double stdStringWidth = 5;
}

StringElement::StringElement(bool isEditable, double minLength, double maxLength, const Vector2d &startPosition) :
	FromToElement(isEditable, minLength, maxLength, startPosition) {

}

double StringElement::getStringWidth() const {
	return stdStringWidth;
}

bool StringElement::containsPoint(const Vector2d &point) const {
	if (this->isErased()) return false;
	Vector2d axis = getEndPosition() - getStartPosition();
	Vector2d translation = -getStartPosition();
	double angle = -(Vector2d(1, 0).angleTo(axis));

	Vector2d translatedPoint = translation + point;
	double transformedX = cos(angle) * translatedPoint.getX() - sin(angle) * translatedPoint.getY();
	double transformedY = sin(angle) * translatedPoint.getX() + cos(angle) * translatedPoint.getY();

	return transformedX >= 0 && transformedX <= axis.norm() && fabs(transformedY) <= (getStringWidth() / 2);
}

void StringElement::buildParticlesAndSprings() {
	Vector2d xAxis = getEndPosition() - getStartPosition();
	double length = xAxis.norm();
	int requiredMasses = static_cast<int>(ceil(length / stdMaxMassDistance) + 1.0);
	double massDistance = length / requiredMasses;

	xAxis.normalize();

	for (int i = 0; i < requiredMasses; i++) {
		Vector2d massPosition = getStartPosition() + (xAxis * (i * massDistance));
		particles.push_back(createParticle(stdMassValue, stdMassRadius, massPosition));
	}

	for (int i = 0; i < requiredMasses - 1; i++) {
		springs.push_back(new Spring(*particles[i], *particles[i + 1], stdK));
	}

	if (getFromConnectionPoint().isConnected()) {
		ConnectionPoint::particle_list connectionParticles = getFromConnectionPoint().getConnectionParticles();
		for (ConnectionPoint::particle_list::iterator it = connectionParticles.begin(); it != connectionParticles.end(); ++it) {
			springs.push_back(new Spring(*particles[0], **it, stdK));
		}
	}

	if (getToConnectionPoint().isConnected()) {
		ConnectionPoint::particle_list connectionParticles = getToConnectionPoint().getConnectionParticles();
		for (ConnectionPoint::particle_list::iterator it = connectionParticles.begin(); it != connectionParticles.end(); ++it) {
			springs.push_back(new Spring(*particles[particles.size() - 1], **it, stdK));
		}
	}

}
