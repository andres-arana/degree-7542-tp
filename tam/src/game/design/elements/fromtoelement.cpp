#include "fromtoelement.h"
#include "../move/frommovepoint.h"
#include "../move/fromtomovepoint.h"
#include "../move/tomovepoint.h"
#include "../connect/fromconnectionpoint.h"
#include "../connect/toconnectionpoint.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::move;
using namespace game::design::connect;

FromToElement::FromToElement(bool isEditable, double minLength, double maxLength, const Vector2d &startPosition) :
	Element(isEditable),
	minLength(minLength),
	maxLength(maxLength),
	startPosition(startPosition) {

	this->setEndPosition(Vector2d(startPosition.getX() + minLength, startPosition.getY()));
	if (isEditable) {
		// Agregar move points
		movePoints.push_back(new FromMovePoint(*this));
		movePoints.push_back(new ToMovePoint(*this));
		movePoints.push_back(new FromToMovePoint(*this));
	}

	// Agregar connection points
	connectionPoints.push_back(new FromConnectionPoint(*this));
	connectionPoints.push_back(new ToConnectionPoint(*this));
}

double FromToElement::getMinimumLength() const {
	return minLength;
}

double FromToElement::getMaximumLength() const {
	return maxLength;
}

Vector2d FromToElement::getValidPosition(const Vector2d &startPos, const Vector2d &potentialPos) {

	Vector2d vectorAux = potentialPos - startPos;
	double length = vectorAux.norm();
	vectorAux.normalize();
	if (length == 0) {
		vectorAux.setX(1);
		vectorAux.setY(0);
	}
	if (length > this->maxLength) {
		return startPos + (vectorAux * this->maxLength);
	} else {
		if (length < this->minLength) {
			return startPos + (vectorAux * this->minLength);
		} else {
			return potentialPos;
		}
	}
}

void FromToElement::setStartPosition(const Vector2d &position) {
	startPosition = this->getValidPosition(this->endPosition, position);
	modifiedSignal();
}

void FromToElement::setUncheckedStartPosition(const Vector2d &position) {
	startPosition = position;
	modifiedSignal();
}

const Vector2d &FromToElement::getStartPosition() const {
	return startPosition;
}

void FromToElement::setEndPosition(const Vector2d &position) {
	endPosition = this->getValidPosition(this->startPosition, position);
	modifiedSignal();
}

void FromToElement::setUncheckedEndPosition(const Vector2d &position) {
	endPosition = position;
	modifiedSignal();
}

const Vector2d &FromToElement::getEndPosition() const {
	return endPosition;
}

ConnectionPoint &FromToElement::getFromConnectionPoint() {
	return *connectionPoints[0];
}

ConnectionPoint &FromToElement::getToConnectionPoint() {
	return *connectionPoints[1];
}
