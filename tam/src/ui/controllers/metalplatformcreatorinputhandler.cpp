#include "metalplatformcreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

MetalPlatformCreatorInputHandler::MetalPlatformCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container) :
	platform(NULL), factory(factory), container(container) {

}

void MetalPlatformCreatorInputHandler::handleMousePressed(int x, int y) {
	platform = factory.createMetalPlatform(Vector2d(x, y));
	if (platform) {
		container.addMetalPlatform(platform);
	}
}

void MetalPlatformCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (platform) {
		platform->setEndPosition(Vector2d(x, y));
	}
}

void MetalPlatformCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (platform) {
		platform->setEndPosition(Vector2d(x, y));
	}
}
