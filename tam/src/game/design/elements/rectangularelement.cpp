#include "rectangularelement.h"
#include "utils/math.h"
#include <cmath>

using namespace common::utils;
using namespace game::core;
using namespace game::design::elements;
using namespace game::design::connect;
using namespace std;

namespace {
	const double stdK = 6000;
	const double stdMaxMassRadius = 5;
	const double stdMassSeparation = 0.30;
	const double stdMassValue = 0.33;
	const double stdThickness = 10;
}

RectangularElement::RectangularElement(bool isEditable, double minLength, double maxLength, const Vector2d &startPosition) :
	FromToElement(isEditable, minLength, maxLength, startPosition) {

}

double RectangularElement::getThickness() const {
	return stdThickness;
}

const Vector2d RectangularElement::getUpperLeftCorner() const {
	return getStartPosition() + getNormalYAxis() * (stdThickness + stdMaxMassRadius);
}

const Vector2d RectangularElement::getLowerLeftCorner() const {
	return getStartPosition() - getNormalYAxis() * (stdThickness + stdMaxMassRadius);
}

const Vector2d RectangularElement::getLowerRightCorner() const {
	return getEndPosition() - getNormalYAxis() * (stdThickness + stdMaxMassRadius);
}

const Vector2d RectangularElement::getUpperRightCorner() const {
	return getEndPosition() + getNormalYAxis() * (stdThickness + stdMaxMassRadius);
}

bool RectangularElement::containsPoint(const Vector2d &point) const {
	if (this->isErased()) return false;
	Vector2d axis = getEndPosition() - getStartPosition();
	Vector2d translation = -getStartPosition();
	double angle = -(Vector2d(1, 0).angleTo(axis));

	Vector2d translatedPoint = translation + point;
	double transformedX = cos(angle) * translatedPoint.getX() - sin(angle) * translatedPoint.getY();
	double transformedY = sin(angle) * translatedPoint.getX() + cos(angle) * translatedPoint.getY();

	return transformedX >= 0 && transformedX <= axis.norm() && fabs(transformedY) <= stdThickness;
}

void RectangularElement::buildParticlesAndSprings() {
	Vector2d xAxis = getEndPosition() - getStartPosition();
	double barLength = xAxis.norm();
	int requiredMasses = static_cast<int>(ceil(barLength / ((2 * stdMaxMassRadius) + stdMassSeparation)));
	double massRadius = (barLength / static_cast<double>(2 * requiredMasses)) - stdMassSeparation;

	xAxis.normalize();

	double angle = -((Math::PI / 2) - (xAxis.angleTo(Vector2d(0, 1))));

	Vector2d yAxis(sin(angle), cos(angle));

	// Particulas
	for (int i = 0; i < requiredMasses; i++) {
		Vector2d upperPos = getStartPosition() + (xAxis * (i * ((2 * massRadius) + stdMassSeparation))) + (yAxis * stdThickness);
		Vector2d lowerPos = getStartPosition() + (xAxis * (i * ((2 * massRadius) + stdMassSeparation))) - (yAxis * stdThickness);

		particles.push_back(createParticle(stdMassValue, massRadius, upperPos));
		particles.push_back(createParticle(stdMassValue, massRadius, lowerPos));
	}

	// Resortes de conexión (si corresponde)
	if (getFromConnectionPoint().isConnected()) {
		for (int i = 0; i < 2; i++) {
			ConnectionPoint::particle_list connectionParticles = getFromConnectionPoint().getConnectionParticles();
			for (ConnectionPoint::particle_list::iterator it = connectionParticles.begin(); it != connectionParticles.end(); ++it) {
				springs.push_back(new Spring(*particles[i], **it, stdK));
			}
		}
	}

	if (getToConnectionPoint().isConnected()) {
		for (int i = 0; i < 2; i++) {
			ConnectionPoint::particle_list connectionParticles = getToConnectionPoint().getConnectionParticles();
			for (ConnectionPoint::particle_list::iterator it = connectionParticles.begin(); it != connectionParticles.end(); ++it) {
				springs.push_back(new Spring(*particles[particles.size() - 2 + i], **it, stdK));
			}
		}
	}

	// Resortes verticales
	for (int i = 0; i < 2 * requiredMasses; i += 2) {
		springs.push_back(new Spring(*particles[i], *particles[i + 1], stdK));
	}

	// Resortes horizontales
	for (int i = 0; i < 2 * (requiredMasses - 1); i++) {
		springs.push_back(new Spring(*particles[i], *particles[i + 2], stdK));
	}

	// Resortes diagonales
	for (int i = 0; i <= 2 * (requiredMasses - 2); i += 2) {
		springs.push_back(new Spring(*particles[i], *particles[i + 3], stdK));
	}

	for (int i = 1; i < 2 * (requiredMasses - 1); i += 2) {
		springs.push_back(new Spring(*particles[i], *particles[i + 1], stdK));
	}
}

Vector2d RectangularElement::getNormalYAxis() const {
	Vector2d xAxis = getEndPosition() - getStartPosition();
	xAxis.normalize();

	double angle = -((Math::PI / 2) - (xAxis.angleTo(Vector2d(0, 1))));
	return Vector2d(sin(angle), cos(angle));
}
