#include "deleteinputhandler.h"
#include "design/elements/element.h"

using namespace game::core;
using namespace game::design;
using namespace game::design::elements;
using namespace ui::controllers;

DeleteInputHandler::DeleteInputHandler(ElementContainer &container) :
	container(container) {

}

void DeleteInputHandler::handleMousePressed(int x, int y) {
	// No hacemos nada.
}

void DeleteInputHandler::handleMouseRelease(int x, int y) {
	Element* element = container.getElementAt(Vector2d(x, y));
	if (element) {
		element->erase();
	}
}

void DeleteInputHandler::handleMouseMotion(int x, int y) {
	// No hacemos nada.
}
