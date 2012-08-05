#include "metalbar.h"

using namespace game::core;
using namespace game::design::elements;

MetalBar::MetalBar(bool isEditable, double minLength, double maxLength, const Vector2d &startPosition) :
	RectangularElement(isEditable, minLength, maxLength, startPosition) {

}

Particle *MetalBar::createParticle(double mass, double radius, const Vector2d &position) const {
	Particle *p = new Particle(mass, radius, position);
	p->setCollisionable(false);
	return p;
}
