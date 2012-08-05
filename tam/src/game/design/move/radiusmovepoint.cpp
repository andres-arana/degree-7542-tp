#include "radiusmovepoint.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::move;

RadiusMovePoint::RadiusMovePoint(CenterRadiusElement &element)
	: element(element) {

}

Vector2d RadiusMovePoint::getPosition() const {
	return element.getRadiusPosition();
}

void RadiusMovePoint::move(const Vector2d &newPosition) {
	element.setRadiusPosition(newPosition);
}

