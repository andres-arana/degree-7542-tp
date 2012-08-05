#include "elementcontainer.h"
#include "utils/collections.h"

using namespace std;
using namespace game::core;
using namespace game::design;
using namespace game::design::elements;
using namespace game::design::move;
using namespace game::design::connect;

ElementContainer::ElementContainer() :
	ball(NULL) {

}

void ElementContainer::setBall(Ball *ball) {
	this->ball = ball;
	addGenericElement(ball);
}

void ElementContainer::addCanvasTape(CanvasTape *canvasTape) {
	canvasTapeCollection.push_back(canvasTape);
	addGenericElement(canvasTape);
}

void ElementContainer::addConnection(Connection *connection) {
	connectionCollection.push_back(connection);
	addGenericElement(connection);
}

void ElementContainer::addExitArea(ExitArea *exitArea) {
	exitAreaCollection.push_back(exitArea);
	addGenericElement(exitArea);
}

void ElementContainer::addFixedPoint(FixedPoint *fixedPoint) {
	fixedPointCollection.push_back(fixedPoint);
	addGenericElement(fixedPoint);
}

void ElementContainer::addMass(Mass *mass) {
	massCollection.push_back(mass);
	addGenericElement(mass);
}

void ElementContainer::addMetalBar(MetalBar *bar) {
	metalBarCollection.push_back(bar);
	addGenericElement(bar);
}

void ElementContainer::addMetalPlatform(MetalPlatform *platform) {
	metalPlatformCollection.push_back(platform);
	addGenericElement(platform);
}

void ElementContainer::addObstacle(Obstacle *obstacle) {
	obstacleCollection.push_back(obstacle);
	addGenericElement(obstacle);
}

void ElementContainer::addRocket(Rocket *rocket) {
	rocketCollection.push_back(rocket);
	addGenericElement(rocket);
}

void ElementContainer::addRope(Rope *rope) {
	ropeCollection.push_back(rope);
	addGenericElement(rope);
}

void ElementContainer::addWheel(Wheel *wheel) {
	wheelCollection.push_back(wheel);
	addGenericElement(wheel);
}

const Ball* ElementContainer::getBall() const {
	return ball;
}

const ElementContainer::CanvasTapeCollection& ElementContainer::getCanvasTapeCollection() const {
	return canvasTapeCollection;
}

const ElementContainer::ConnectionCollection& ElementContainer::getConnectionCollection() const {
	return connectionCollection;
}

const ElementContainer::ExitAreaCollection& ElementContainer::getExitAreaCollection() const {
	return exitAreaCollection;
}

const ElementContainer::FixedPointCollection& ElementContainer::getFixedPointCollection() const {
	return fixedPointCollection;
}

const ElementContainer::MassCollection& ElementContainer::getMassCollection() const {
	return massCollection;
}

const ElementContainer::MetalBarCollection& ElementContainer::getMetalBarCollection() const {
	return metalBarCollection;
}

const ElementContainer::MetalPlatformCollection& ElementContainer::getMetalPlatformCollection() const {
	return metalPlatformCollection;
}

const ElementContainer::ObstacleCollection& ElementContainer::getObstacleCollection() const {
	return obstacleCollection;
}

const ElementContainer::RocketCollection& ElementContainer::getRocketCollection() const {
	return rocketCollection;
}

const ElementContainer::RopeCollection& ElementContainer::getRopeCollection() const {
	return ropeCollection;
}

const ElementContainer::WheelCollection& ElementContainer::getWheelCollection() const {
	return wheelCollection;
}

ElementContainer::ElementCollection& ElementContainer::getElementCollection() {
	return elementCollection;
}

const ElementContainer::ElementCollection& ElementContainer::getElementConstCollection() const {
	return elementCollection;
}

Element *ElementContainer::getElementAt(const Vector2d &position) {
	ElementIterator it = find_if(elementCollection.begin(), elementCollection.end(), ElementContainsPointPredicate(position));
	if (it != elementCollection.end()) {
		return *it;
	} else {
		return NULL;
	}
}


MovePoint *ElementContainer::getMovePointAt(const Vector2d &point) {
	typedef vector<MovePoint *>::const_iterator MovePointIterator;

	for (ElementIterator eit = elementCollection.begin(); eit != elementCollection.end(); ++eit) {
		if (!(*eit)->isErased()) {
			MovePointIterator mit = find_if((*eit)->getMovePoints().begin(), (*eit)->getMovePoints().end(), MovePointContainsPointPredicate(point));

			if (mit != (*eit)->getMovePoints().end()) {
				return *mit;
			}
		}
	}
	return NULL;
}

ConnectionPoint *ElementContainer::getConnectionPointAt(const Vector2d &point) {
	typedef vector<ConnectionPoint *>::const_iterator ConnectionPointIterator;

	for (ElementIterator eit = elementCollection.begin(); eit != elementCollection.end(); ++eit) {
		if (!(*eit)->isErased()) {
			ConnectionPointIterator cit = find_if((*eit)->getConnectionPoints().begin(), (*eit)->getConnectionPoints().end(), ConnectionPointContainsPointPredicate(point));

			if (cit != (*eit)->getConnectionPoints().end()) {
				return *cit;
			}
		}
	}
	return NULL;
}

void ElementContainer::clearElements() {
	common::utils::DeleteAndClearElements(elementCollection);
	ball = NULL;
	canvasTapeCollection.clear();
	connectionCollection.clear();
	exitAreaCollection.clear();
	fixedPointCollection.clear();
	massCollection.clear();
	metalBarCollection.clear();
	metalPlatformCollection.clear();
	obstacleCollection.clear();
	ropeCollection.clear();
	rocketCollection.clear();
	wheelCollection.clear();
	launchDesignModifiedSignal();
}

ElementContainer::design_modified_signal_type &ElementContainer::designModified() {
	return designModifiedSignal;
}

ElementContainer::~ElementContainer() {
	common::utils::DeleteAndClearElements(elementCollection);
}

void ElementContainer::launchDesignModifiedSignal() {
	designModifiedSignal();
}

void ElementContainer::addGenericElement(Element* element) {
	element->modified().connect(sigc::mem_fun(*this, &ElementContainer::launchDesignModifiedSignal));
	element->erased().connect(sigc::mem_fun(*this, &ElementContainer::launchDesignModifiedSignal));
	elementCollection.push_back(element);
	launchDesignModifiedSignal();
}
