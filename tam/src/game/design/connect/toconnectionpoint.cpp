#include "toconnectionpoint.h"

using namespace game::design::elements;
using namespace game::design::connect;
using namespace game::core;

ToConnectionPoint::ToConnectionPoint(FromToElement &element) :
	element(element) {

}

Vector2d ToConnectionPoint::getPosition() const {
	Vector2d axis = element.getEndPosition() - element.getStartPosition();
	axis.normalize();
	return element.getEndPosition() + (axis * 5);
}

Element &ToConnectionPoint::getParentElement() {
	return element;
}
