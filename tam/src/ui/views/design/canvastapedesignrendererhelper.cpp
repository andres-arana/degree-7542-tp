#include "canvastapedesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

CanvasTapeDesignRendererHelper::CanvasTapeDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void CanvasTapeDesignRendererHelper::renderCanvasTape(const CanvasTape &canvasTape) const {
	if (canvasTape.isErased()) return;

	Color whiteColor = Color::WHITE;
	drawingContext->save();
	drawingContext->set_line_width(canvasTape.getStringWidth());
	drawingContext->set_source_rgb(whiteColor.getRed(), whiteColor.getGreen(),
			whiteColor.getBlue());
	drawingContext->move_to(canvasTape.getStartPosition().getX(),
			canvasTape.getStartPosition().getY());

	drawingContext->line_to(canvasTape.getEndPosition().getX(),
			canvasTape.getEndPosition().getY());

	drawingContext->stroke();
	drawingContext->restore();
}

