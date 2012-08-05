#include "fixedpointdesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

FixedPointDesignRendererHelper::FixedPointDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void FixedPointDesignRendererHelper::renderFixedPoint(const FixedPoint &fixedPoint) const {
	if (fixedPoint.isErased()) return;

	Color darkGreen = Color::ALPHA_DARK_GREEN;
	double x = fixedPoint.getPosition().getX();
	double y = fixedPoint.getPosition().getY();

	drawingContext->save();
	drawingContext->set_source_rgba(darkGreen.getRed(), darkGreen.getGreen(),
			darkGreen.getBlue(), darkGreen.getAlpha());
	drawingContext->arc(x, y, fixedPoint.getRadius(), 0, 2 * M_PI);
	drawingContext->fill();
	drawingContext->restore();
}

