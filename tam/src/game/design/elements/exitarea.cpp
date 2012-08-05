#include "exitarea.h"
#include <cmath>

using namespace std;
using namespace game::design::elements;
using namespace game::core;

ExitArea::ExitArea(bool isEditable) :
	CenterRadiusElement(isEditable, 20, 50) {

}

void ExitArea::buildParticlesAndSprings() {
	return;
}

bool ExitArea::containsBall(const Ball &ball) {
	double distance = ball.getDynamicPosition().distanceTo(getPosition());

	return distance <= fabs(ball.getRadius() - getRadius());
}
