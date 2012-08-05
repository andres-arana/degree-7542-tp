#include "ball.h"

using namespace game::core;
using namespace game::design::elements;

Ball::Ball(bool isEditable, double mass, double minRadius, double maxRadius) :
	CenterRadiusElement(isEditable, minRadius, maxRadius),
	mass(mass) {

}

double Ball::getMass() const {
	return mass;
}

const Vector2d &Ball::getDynamicPosition() const {
	return particles[0]->getPosition();
}

void Ball::buildParticlesAndSprings() {
	particles.push_back(new Particle(mass, getRadius(), getPosition()));
}

