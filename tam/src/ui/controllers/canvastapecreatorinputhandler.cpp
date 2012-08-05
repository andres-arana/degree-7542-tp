#include "canvastapecreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

CanvasTapeCreatorInputHandler::CanvasTapeCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container)
	: canvasTape(NULL), factory(factory), container(container) {

}

void CanvasTapeCreatorInputHandler::handleMousePressed(int x, int y) {
	canvasTape = factory.createCanvasTape(Vector2d(x, y));
	if (canvasTape) {
		container.addCanvasTape(canvasTape);
	}
}

void CanvasTapeCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (canvasTape) {
		canvasTape->setEndPosition(Vector2d(x, y));
	}
}

void CanvasTapeCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (canvasTape) {
		canvasTape->setEndPosition(Vector2d(x, y));
	}
}
