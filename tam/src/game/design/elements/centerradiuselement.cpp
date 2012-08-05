#include "centerradiuselement.h"
#include "../move/radiusmovepoint.h"
#include "../move/centermovepoint.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::move;

CenterRadiusElement::CenterRadiusElement(bool isEditable, double minRadius, double maxRadius) :
	Element(isEditable),
	minRadius(minRadius),
	maxRadius(maxRadius) {

	setRadius(minRadius);
	if (isEditable) {
		// Agregar move points
		movePoints.push_back(new CenterMovePoint(*this));
		movePoints.push_back(new RadiusMovePoint(*this));
	}
}

double CenterRadiusElement::getValidRadius(double potentialRadius) {
	if (potentialRadius < minRadius) {
		return minRadius;
	} else if (potentialRadius > maxRadius) {
		return maxRadius;
	}
	return potentialRadius;
}

const Vector2d CenterRadiusElement::getRadiusPosition() const {
	return radiusPosition;
}

void CenterRadiusElement::setRadiusPosition(const Vector2d &value) {
	Vector2d axis = value - position;
	if (axis.norm() == 0) {
		axis = Vector2d(1, 0);
	}
	double radius = getValidRadius(axis.norm());
	axis.normalize();
	radiusPosition = position + (axis * radius);
	modifiedSignal();
}

double CenterRadiusElement::getRadius() const {
	return position.distanceTo(radiusPosition);
}

void CenterRadiusElement::setRadius(double value) {
	Vector2d newRadiusPosition = position + Vector2d(value, 0);
	setRadiusPosition(newRadiusPosition);
	modifiedSignal();
}
double CenterRadiusElement::getMinRadius() const {
	return minRadius;
}

double CenterRadiusElement::getMaxRadius() const {
	return maxRadius;
}

void CenterRadiusElement::setPosition(const Vector2d &value) {
	Vector2d delta = value - position;
	position += delta;
	radiusPosition += delta;
	modifiedSignal();
}

const Vector2d CenterRadiusElement::getPosition() const {
	return position;
}

bool CenterRadiusElement::containsPoint(const Vector2d& point) const {
	if (this->isErased()) return false;
	return point.distanceTo(position) <= getRadius();
}
