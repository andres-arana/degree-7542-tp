#include "element.h"
#include "utils/collections.h"
#include <algorithm>

using namespace std;
using namespace game::core;
using namespace game::design::elements;

Element::Element(bool isEditable) :
	hasBeenErased(false),
	editable(isEditable) {
}

void Element::build(PhysicsEngine &engine) {
	if (this->isErased()) return;
	buildParticlesAndSprings();

	typedef particle_list::iterator p_iter;
	for (p_iter it = particles.begin(); it != particles.end(); it++) {
		engine.registerParticle(*it);
	}
}

void Element::scrap() {
	common::utils::DeleteAndClearElements(springs);
	common::utils::DeleteAndClearElements(particles);
}

const Element::particle_list &Element::getParticles() const {
	return particles;
}

const Element::spring_list &Element::getSprings() const {
	return springs;
}

const Element::mpoint_list &Element::getMovePoints() const {
	return movePoints;
}

const Element::cpoint_list &Element::getConnectionPoints() const {
	return connectionPoints;
}

Element::~Element() {
	scrap();
	common::utils::DeleteAndClearElements(movePoints);
	common::utils::DeleteAndClearElements(connectionPoints);
}

void Element::erase() {
	if (this->isEditable()) {
		this->hasBeenErased = true;
		erasedSignal();
	}
}

bool Element::isErased() const {
	return this->hasBeenErased;
}

bool Element::isEditable() const {
	return this->editable;
}

Element::modified_signal_type &Element::modified() {
	return modifiedSignal;
}

Element::erased_signal_type &Element::erased() {
	return erasedSignal;
}

ElementContainsPointPredicate::ElementContainsPointPredicate(const Vector2d &point) :
	point(point) {

}

bool ElementContainsPointPredicate::operator ()(const Element *element) const {
	return element->containsPoint(point);
}
