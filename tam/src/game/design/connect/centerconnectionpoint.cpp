#include "centerconnectionpoint.h"

using namespace game::design::elements;
using namespace game::design::connect;
using namespace game::core;

CenterConnectionPoint::CenterConnectionPoint(CenterRadiusElement& element) :
	element(element) {

}

Vector2d CenterConnectionPoint::getPosition() const {
	return element.getPosition();
}

Element &CenterConnectionPoint::getParentElement() {
	return element;
}
