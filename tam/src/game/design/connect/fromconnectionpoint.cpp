#include "fromconnectionpoint.h"

using namespace game::design::elements;
using namespace game::design::connect;
using namespace game::core;

FromConnectionPoint::FromConnectionPoint(FromToElement &element) :
	element(element) {

}

Vector2d FromConnectionPoint::getPosition() const {
	Vector2d axis = element.getStartPosition() - element.getEndPosition();
	axis.normalize();
	return element.getStartPosition() + (axis * 5);
}

Element &FromConnectionPoint::getParentElement() {
	return element;
}
