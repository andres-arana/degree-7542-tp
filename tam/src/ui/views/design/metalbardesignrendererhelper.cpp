#include "metalbardesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

MetalBarDesignRendererHelper::MetalBarDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void MetalBarDesignRendererHelper::renderMetalBar(const MetalBar &bar) const {
	if (bar.isErased()) return;

	Color alphaWhite = Color::ALPHA_WHITE;
	Vector2d ul = bar.getUpperLeftCorner();
	Vector2d ll = bar.getLowerLeftCorner();
	Vector2d lr = bar.getLowerRightCorner();
	Vector2d ur = bar.getUpperRightCorner();

	drawingContext->save();
	drawingContext->set_source_rgba(alphaWhite.getRed(), alphaWhite.getGreen(),
			alphaWhite.getBlue(), alphaWhite.getAlpha());
	drawingContext->move_to(ul.getX(), ul.getY());

	drawingContext->line_to(ll.getX(), ll.getY());
	drawingContext->line_to(lr.getX(), lr.getY());
	drawingContext->line_to(ur.getX(), ur.getY());
	drawingContext->line_to(ul.getX(), ul.getY());
	drawingContext->fill();

	drawingContext->restore();
}

