#include "moveinputhandler.h"

using namespace game::core;
using namespace game::design;
using namespace ui::controllers;
using namespace ui::views;

MoveInputHandler::MoveInputHandler(GameRenderArea &renderArea, ElementContainer &container)
	: renderArea(renderArea), container(container), selectedMovePoint(0) {
	renderArea.enableLayer(GameRenderArea::MovePointLayer);
	renderArea.redraw();
}

void MoveInputHandler::handleMousePressed(int x, int y) {
	selectedMovePoint = container.getMovePointAt(Vector2d(x, y));
	if (selectedMovePoint) {
		selectedMovePoint->move(Vector2d(x, y));
	}
}

void MoveInputHandler::handleMouseRelease(int x, int y) {
	if (selectedMovePoint) {
		selectedMovePoint->move(Vector2d(x, y));
	}
}

void MoveInputHandler::handleMouseMotion(int x, int y) {
	if (selectedMovePoint) {
		selectedMovePoint->move(Vector2d(x, y));
	}
}

MoveInputHandler::~MoveInputHandler() {
	renderArea.disableLayer(GameRenderArea::MovePointLayer);
	renderArea.redraw();
}
