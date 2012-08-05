#include "rocketcreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

RocketCreatorInputHandler::RocketCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container)
	: rocket(NULL), factory(factory), container(container) {

}

void RocketCreatorInputHandler::handleMousePressed(int x, int y) {
	rocket = factory.createRocket(Vector2d(x, y));
	if (rocket) {
		container.addRocket(rocket);
	}
}

void RocketCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (rocket) {
		rocket->setTarget(Vector2d(x, y));
	}
}

void RocketCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (rocket) {
		rocket->setTarget(Vector2d(x, y));
	}
}
