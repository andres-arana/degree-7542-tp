#include "masscreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

MassCreatorInputHandler::MassCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container) :
	mass(NULL), factory(factory), container(container) {

}

void MassCreatorInputHandler::handleMousePressed(int x, int y) {
	mass = factory.createMass();
	if (mass) {
		mass->setPosition(Vector2d(x, y));
		container.addMass(mass);
	}
}

void MassCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (mass) {
		mass->setRadiusPosition(Vector2d(x, y));
	}
}

void MassCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (mass) {
		mass->setRadiusPosition(Vector2d(x, y));
	}
}
