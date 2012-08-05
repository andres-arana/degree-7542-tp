#include "tomovepoint.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::move;

ToMovePoint::ToMovePoint(FromToElement &element)
	: element(element) {

}

Vector2d ToMovePoint::getPosition() const {
	return element.getEndPosition();
}

void ToMovePoint::move(const Vector2d &newPosition) {
	element.setEndPosition(newPosition);
}
