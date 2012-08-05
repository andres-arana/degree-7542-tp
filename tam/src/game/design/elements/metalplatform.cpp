#include "metalplatform.h"

using namespace game::core;
using namespace game::design::elements;

MetalPlatform::MetalPlatform(bool isEditable, double minLength, double maxLength, const Vector2d &startPosition)	:
	RectangularElement(isEditable, minLength, maxLength, startPosition) {

}

Particle *MetalPlatform::createParticle(double mass, double radius, const core::Vector2d &position) const {
	return new Particle(mass, radius, position);
}
