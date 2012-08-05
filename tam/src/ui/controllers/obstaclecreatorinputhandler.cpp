#include "obstaclecreatorinputhandler.h"

using namespace game::design;
using namespace game::core;
using namespace ui::controllers;

ObstacleCreatorInputHandler::ObstacleCreatorInputHandler(
		ElementFactory &factory,
		ElementContainer &container) :
	obstacle(NULL), factory(factory), container(container) {

}

void ObstacleCreatorInputHandler::handleMousePressed(int x, int y) {
	obstacle = factory.createObstacle(Vector2d(x, y));
	if (obstacle) {
		container.addObstacle(obstacle);
	}
}

void ObstacleCreatorInputHandler::handleMouseRelease(int x, int y) {
	if (obstacle) {
		obstacle->setEndPosition(Vector2d(x, y));
	}
}

void ObstacleCreatorInputHandler::handleMouseMotion(int x, int y) {
	if (obstacle) {
		obstacle->setEndPosition(Vector2d(x, y));
	}
}
