#include "ropecreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

RopeCreatorInputHandler::RopeCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container) :
	rope(NULL), factory(factory), container(container) {

}

void RopeCreatorInputHandler::handleMousePressed(int x, int y) {
	rope = factory.createRope(Vector2d(x, y));
	if (rope) {
		container.addRope(rope);
	}
}

void RopeCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (rope) {
		rope->setEndPosition(Vector2d(x, y));
	}
}

void RopeCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (rope) {
		rope->setEndPosition(Vector2d(x, y));
	}
}
