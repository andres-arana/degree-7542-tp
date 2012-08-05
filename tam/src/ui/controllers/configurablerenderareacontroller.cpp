#include "configurablerenderareacontroller.h"

using namespace ui::controllers;
using namespace ui::views;

ConfigurableRenderAreaController::ConfigurableRenderAreaController(GameRenderArea &renderAreaWidget) :
	currentHandler(NULL), renderArea(renderAreaWidget) {

	renderAreaWidget.signalMousePressed().connect(sigc::mem_fun(*this, &ConfigurableRenderAreaController::onMousePressed));
	renderAreaWidget.signalMouseReleased().connect(sigc::mem_fun(*this, &ConfigurableRenderAreaController::onMouseReleased));
	renderAreaWidget.signalMouseMotion().connect(sigc::mem_fun(*this, &ConfigurableRenderAreaController::onMouseMotion));
}

void ConfigurableRenderAreaController::configureCurrentHandler(RenderAreaInputHandler *handler) {
	if (currentHandler) {
		delete currentHandler;
	}
	currentHandler = handler;
}

void ConfigurableRenderAreaController::onMousePressed(int x, int y) {
	if (currentHandler) {
		currentHandler->handleMousePressed(x, y);
	}
}

void ConfigurableRenderAreaController::onMouseReleased(int x, int y) {
	if (currentHandler) {
		currentHandler->handleMouseRelease(x, y);
	}
}

void ConfigurableRenderAreaController::onMouseMotion(int x, int y) {
	if (currentHandler) {
		currentHandler->handleMouseMotion(x, y);
	}
}

ConfigurableRenderAreaController::~ConfigurableRenderAreaController() {
	if (currentHandler) {
		delete currentHandler;
	}
}
