#include "rocketposmovepoint.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::move;

RocketPosMovePoint::RocketPosMovePoint(Rocket &element)
	: element(element) {

}

Vector2d RocketPosMovePoint::getPosition() const {
	return element.getPosition();
}

void RocketPosMovePoint::move(const Vector2d &newPosition) {
	Vector2d delta = newPosition - element.getPosition();
	element.setPosition(newPosition);
	element.setTarget(element.getTarget() + delta);
}

