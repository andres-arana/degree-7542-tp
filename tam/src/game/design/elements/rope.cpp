#include "rope.h"

using namespace std;
using namespace game::core;
using namespace game::design::elements;

Rope::Rope(bool isEditable, double minLength, double maxLength, const Vector2d &startPosition) :
	StringElement(isEditable, minLength, maxLength, startPosition) {

}

Particle *Rope::createParticle(double mass, double radius, const Vector2d &position) const {
	Particle *p = new Particle(mass, radius, position);
	p->setCollisionable(false);
	return p;
}
