#include "gamerenderarea.h"
#include "utils/collections.h"
#include <algorithm>

using namespace std;
using namespace ui::views;

namespace {
	struct RenderRenderer {
		Cairo::RefPtr<Cairo::Context> drawingContext;

		RenderRenderer(Cairo::RefPtr<Cairo::Context> drawingContext)
			: drawingContext(drawingContext) {

		}

		void operator()(Renderer *renderer) {
			renderer->render(drawingContext);
		}
	};
}

GameRenderArea::GameRenderArea(double scale) :
	layers(OverlayLayer + 1),
	enabledLayers(OverlayLayer + 1, true),
	scale(scale) {
	add_events(Gdk::BUTTON_PRESS_MASK |
		Gdk::BUTTON_RELEASE_MASK |
		Gdk::POINTER_MOTION_MASK |
		Gdk::POINTER_MOTION_HINT_MASK);

	enabledLayers[ElementRuntimeLayer] = false;
	enabledLayers[ConnectPointLayer] = false;
	enabledLayers[MovePointLayer] = false;
	saveLayersState();
}

void GameRenderArea::addRendererToLayer(RenderLayers layer, Renderer *renderer) {
	layers[layer].push_back(renderer);
}

void GameRenderArea::enableLayer(RenderLayers layer) {
	enabledLayers[layer] = true;
}

void GameRenderArea::disableLayer(RenderLayers layer) {
	enabledLayers[layer] = false;
}

void GameRenderArea::saveLayersState() {
	enabledLayersBackup = enabledLayers;
}

void GameRenderArea::restoreLayersState() {
	enabledLayers = enabledLayersBackup;
}

void GameRenderArea::swapToRuntimeMode() {
	enableLayer(ElementRuntimeLayer);
	disableLayer(ElementDesignLayer);
	disableLayer(MovePointLayer);
	disableLayer(ConnectPointLayer);
}

void GameRenderArea::redraw() {
	Glib::RefPtr<Gdk::Window> window = get_window();
	if (window) {
		Gtk::Allocation alloc = get_allocation();
		Gdk::Rectangle r(0, 0, alloc.get_width(), alloc.get_height());
		window->invalidate_rect(r, false);
	}
}

GameRenderArea::mouse_pressed_signal_type &GameRenderArea::signalMousePressed() {
	return mousePressedSignal;
}

GameRenderArea::mouse_released_signal_type &GameRenderArea::signalMouseReleased() {
	return mouseReleasedSignal;
}

GameRenderArea::mouse_motion_signal_type &GameRenderArea::signalMouseMotion() {
	return mouseMotionSignal;
}

GameRenderArea::~GameRenderArea() {
	this->disposeRenderers();
}

void GameRenderArea::disposeRenderers() {
	for (int layer = BackgroundLayer; layer <= OverlayLayer; layer++) {
		common::utils::DeleteAndClearElements(layers[layer]);
	}
}

bool GameRenderArea::on_expose_event(GdkEventExpose* event) {
	Glib::RefPtr<Gdk::Window> window = get_window();
	if (window) {
		Cairo::RefPtr<Cairo::Context> drawingContext = window->create_cairo_context();

		drawingContext->set_line_width(0.5);


		int x = scaleCoordinate(event->area.x);
		int y = scaleCoordinate(event->area.y);
		int width = scaleCoordinate(event->area.width);
		int height = scaleCoordinate(event->area.height);
		drawingContext->rectangle(x, y, width, height);
		drawingContext->clip();

		drawingContext->scale(scale, scale);

		for (int layer = BackgroundLayer; layer <= OverlayLayer; layer++) {
			if (enabledLayers[layer]) {
				for_each(layers[layer].begin(), layers[layer].end(), RenderRenderer(drawingContext));
			}
		}
	}

	return true;
}

bool GameRenderArea::on_button_press_event(GdkEventButton* event) {
	this->setDragCursorType();
	mousePressedSignal(scaleCoordinate(event->x), scaleCoordinate(event->y));
	return true;
}

bool GameRenderArea::on_button_release_event(GdkEventButton* event) {
	this->setDefaultCursorType();
	mouseReleasedSignal(scaleCoordinate(event->x), scaleCoordinate(event->y));
	return true;
}

bool GameRenderArea::on_motion_notify_event(GdkEventMotion* event) {
	if (event->state == GDK_BUTTON1_MASK) {
		mouseMotionSignal(scaleCoordinate(event->x), scaleCoordinate(event->y));
	}
	return true;
}

int GameRenderArea::scaleCoordinate(int coord) const {
	return static_cast<int>(static_cast<double>(coord) / scale);
}

void GameRenderArea::setDefaultCursorType() {
	this->get_window()->set_cursor(Gdk::Cursor(Gdk::HAND2));
}

void GameRenderArea::setDragCursorType() {
	this->get_window()->set_cursor(Gdk::Cursor(Gdk::HAND1));
}
