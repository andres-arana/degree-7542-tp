#include "wheeldesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

WheelDesignRendererHelper::WheelDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void WheelDesignRendererHelper::renderWheel(const Wheel &wheel) const {
	if (wheel.isErased()) return;

	Color white = Color::WHITE;
	double x = wheel.getPosition().getX();
	double y = wheel.getPosition().getY();

	drawingContext->save();
	drawingContext->set_source_rgb(white.getRed(), white.getGreen(),
			white.getBlue());
	drawingContext->arc(x, y, wheel.getRadius(), 0, 2 * M_PI);
	drawingContext->fill();
	drawingContext->restore();
}

