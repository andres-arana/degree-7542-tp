#include "radiusconnectionpoint.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::connect;

RadiusConnectionPoint::RadiusConnectionPoint(CenterRadiusElement &element) :
	element(element) {

}


Vector2d RadiusConnectionPoint::getPosition() const {
	return element.getRadiusPosition();
}

Element &RadiusConnectionPoint::getParentElement() {
	return element;
}
