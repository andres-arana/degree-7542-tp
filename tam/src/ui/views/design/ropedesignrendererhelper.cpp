#include "ropedesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

RopeDesignRendererHelper::RopeDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void RopeDesignRendererHelper::renderRope(const Rope &rope) const {
	if (rope.isErased()) return;

	Color alphaWhite = Color::ALPHA_WHITE;
	drawingContext->save();
	drawingContext->set_line_width(rope.getStringWidth());
	drawingContext->set_source_rgba(alphaWhite.getRed(), alphaWhite.getGreen(),
			alphaWhite.getGreen(), alphaWhite.getAlpha());
	drawingContext->move_to(rope.getStartPosition().getX(),
			rope.getStartPosition().getY());

	drawingContext->line_to(rope.getEndPosition().getX(),
			rope.getEndPosition().getY());

	drawingContext->stroke();
	drawingContext->restore();
}

