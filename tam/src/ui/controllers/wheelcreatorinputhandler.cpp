#include "wheelcreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

WheelCreatorInputHandler::WheelCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container)
	: wheel(NULL), factory(factory), container(container) {

}

void WheelCreatorInputHandler::handleMousePressed(int x, int y) {
	wheel = factory.createWheel();
	if (wheel) {
		wheel->setPosition(Vector2d(x, y));
		container.addWheel(wheel);
	}
}

void WheelCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (wheel) {
		wheel->setRadiusPosition(Vector2d(x, y));
	}
}

void WheelCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (wheel) {
		wheel->setRadiusPosition(Vector2d(x, y));
	}
}
