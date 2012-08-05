#include "ballcreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

BallCreatorInputHandler::BallCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container)
	: ball(NULL), factory(factory), container(container) {

}

void BallCreatorInputHandler::handleMousePressed(int x, int y) {
	ball = factory.createBall();
	if (ball) {
		ball->setPosition(Vector2d(x, y));
		container.setBall(ball);
	}
}

void BallCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (ball) {
		ball->setRadiusPosition(Vector2d(x, y));
	}
}

void BallCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (ball) {
		ball->setRadiusPosition(Vector2d(x, y));
	}
}
