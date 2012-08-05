#include "frommovepoint.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::move;

FromMovePoint::FromMovePoint(FromToElement &element)
	: element(element) {

}

Vector2d FromMovePoint::getPosition() const {
	return element.getStartPosition();
}

void FromMovePoint::move(const Vector2d &newPosition) {
	element.setStartPosition(newPosition);
}

