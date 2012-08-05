#include "connectinputhandler.h"
#include "design/elements/connection.h"

using namespace game::core;
using namespace game::design;
using namespace game::design::elements;
using namespace game::design::connect;
using namespace ui::controllers;
using namespace ui::views;

ConnectInputHandler::ConnectInputHandler(GameRenderArea &renderArea, ElementContainer &container)
	: renderArea(renderArea), container(container) {
	renderArea.enableLayer(GameRenderArea::ConnectPointLayer);
	renderArea.redraw();
}

void ConnectInputHandler::handleMousePressed(int x, int y) {
	firstPoint = container.getConnectionPointAt(Vector2d(x, y));
}

void ConnectInputHandler::handleMouseRelease(int x, int y) {
	secondPoint = container.getConnectionPointAt(Vector2d(x, y));

	if (firstPoint && secondPoint && firstPoint != secondPoint) {
		Connection *connection = new Connection(*firstPoint, *secondPoint);
		container.addConnection(connection);
	}
}

void ConnectInputHandler::handleMouseMotion(int x, int y) {
	// No hacemos nada
}

ConnectInputHandler::~ConnectInputHandler() {
	renderArea.disableLayer(GameRenderArea::ConnectPointLayer);
	renderArea.redraw();
}
