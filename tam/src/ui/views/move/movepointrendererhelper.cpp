#include "movepointrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::move;

MovePointDesignRendererHelper::MovePointDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void MovePointDesignRendererHelper::renderMovePoints(const Element &element) const {
	if (!element.isErased()) {
		Color alphaGreen = Color::ALPHA_GREEN;
		typedef Element::mpoint_list::const_iterator iterator;
		for (iterator it = element.getMovePoints().begin(); it != element.getMovePoints().end(); ++it) {
			double x = (*it)->getPosition().getX();
			double y = (*it)->getPosition().getY();

			drawingContext->save();
			drawingContext->set_source_rgba(alphaGreen.getRed(),
					alphaGreen.getGreen(), alphaGreen.getBlue(), alphaGreen.getAlpha());
			drawingContext->arc(x, y, (*it)->getRadius(), 0, 2 * M_PI);
			drawingContext->fill();
			drawingContext->restore();
		}
	}
}

