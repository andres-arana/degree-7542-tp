#include "centermovepoint.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::move;

CenterMovePoint::CenterMovePoint(CenterRadiusElement &element)
	: element(element) {

}

Vector2d CenterMovePoint::getPosition() const {
	return element.getPosition();
}

void CenterMovePoint::move(const Vector2d &newPosition) {
	element.setPosition(newPosition);
}

