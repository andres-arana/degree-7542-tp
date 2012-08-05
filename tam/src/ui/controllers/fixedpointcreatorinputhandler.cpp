#include "fixedpointcreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

FixedPointCreatorInputHandler::FixedPointCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container) :
	fixedPoint(NULL), factory(factory), container(container) {

}

void FixedPointCreatorInputHandler::handleMousePressed(int x, int y) {
	fixedPoint = factory.createFixedPoint();
	if (fixedPoint) {
		fixedPoint->setPosition(Vector2d(x, y));
		container.addFixedPoint(fixedPoint);
	}
}

void FixedPointCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (fixedPoint) {
		fixedPoint->setRadiusPosition(Vector2d(x, y));
	}
}

void FixedPointCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (fixedPoint) {
		fixedPoint->setRadiusPosition(Vector2d(x, y));
	}
}
