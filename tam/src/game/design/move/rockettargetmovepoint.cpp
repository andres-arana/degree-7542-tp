#include "rockettargetmovepoint.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::move;

RocketTargetMovePoint::RocketTargetMovePoint(Rocket &element)
	: element(element) {

}

Vector2d RocketTargetMovePoint::getPosition() const {
	return element.getTarget();
}

void RocketTargetMovePoint::move(const Vector2d &newPosition) {
	element.setTarget(newPosition);
}

