#include "exitareacreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

ExitAreaCreatorInputHandler::ExitAreaCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container)
	: exitArea(NULL), factory(factory), container(container) {

}

void ExitAreaCreatorInputHandler::handleMousePressed(int x, int y) {
	exitArea = factory.createExitArea();
	if (exitArea) {
		exitArea->setPosition(Vector2d(x, y));
		container.addExitArea(exitArea);
	}
}

void ExitAreaCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (exitArea) {
		exitArea->setRadiusPosition(Vector2d(x, y));
	}
}

void ExitAreaCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (exitArea) {
		exitArea->setRadiusPosition(Vector2d(x, y));
	}
}
