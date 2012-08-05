#include "fromtomovepoint.h"

using namespace game::core;
using namespace game::design::elements;
using namespace game::design::move;

FromToMovePoint::FromToMovePoint(FromToElement &element)
	: element(element) {

}

Vector2d FromToMovePoint::getPosition() const {
	Vector2d axis = element.getEndPosition() - element.getStartPosition();
	double centerDistance = axis.norm() / 2;
	axis.normalize();

	return element.getStartPosition() + (axis * centerDistance);
}

void FromToMovePoint::move(const Vector2d &newPosition) {
	Vector2d delta = newPosition - getPosition();
	element.setUncheckedStartPosition(element.getStartPosition() + delta);
	element.setUncheckedEndPosition(element.getEndPosition() + delta);
}

