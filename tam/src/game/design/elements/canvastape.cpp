#include "canvastape.h"

using namespace game::core;
using namespace game::design::elements;

CanvasTape::CanvasTape(bool isEditable, double minLength, double maxLength, const Vector2d &startPosition) :
	StringElement(isEditable, minLength, maxLength, startPosition) {

}

Particle *CanvasTape::createParticle(double mass, double radius, const Vector2d &position) const {
	return new Particle(mass, radius, position);
}
