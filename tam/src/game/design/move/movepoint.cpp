#include "movepoint.h"

using namespace game::core;
using namespace game::design::move;

namespace {
	const double stdRadius = 10;
}

double MovePoint::getRadius() const {
	return stdRadius;
}

bool MovePoint::containsPoint(const Vector2d &point) const {
	return stdRadius >= point.distanceTo(getPosition());
}

MovePointContainsPointPredicate::MovePointContainsPointPredicate(const Vector2d &point) :
	point(point) {

}

bool MovePointContainsPointPredicate::operator()(const MovePoint *movePoint) const {
	return movePoint->containsPoint(point);
}
