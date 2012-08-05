#include "obstacle.h"

using namespace game::core;
using namespace game::design::elements;

Obstacle::Obstacle(bool isEditable, const Vector2d &startPosition, double minLength, double maxLength)	:
	RectangularElement(isEditable, minLength, maxLength, startPosition) {

}

Particle *Obstacle::createParticle(double mass, double radius, const core::Vector2d &position) const {
	Particle *p = new Particle(mass, radius, position);
	p->setFixed(true);
	return p;
}
