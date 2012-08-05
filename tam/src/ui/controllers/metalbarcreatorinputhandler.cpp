#include "metalbarcreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

MetalBarCreatorInputHandler::MetalBarCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container) :
	bar(NULL), factory(factory), container(container) {

}

void MetalBarCreatorInputHandler::handleMousePressed(int x, int y) {
	bar = factory.createMetalBar(Vector2d(x, y));
	if (bar) {
		container.addMetalBar(bar);
	}
}

void MetalBarCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (bar) {
		bar->setEndPosition(Vector2d(x, y));
	}
}

void MetalBarCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (bar) {
		bar->setEndPosition(Vector2d(x, y));
	}
}
