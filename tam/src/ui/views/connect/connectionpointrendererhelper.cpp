#include "connectionpointrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::connect;

ConnectionPointDesignRendererHelper::ConnectionPointDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void ConnectionPointDesignRendererHelper::renderConnectionPoints(const Element &element) const {
	if (!element.isErased()) {
		Color alphaBlue = Color::ALPHA_BLUE;
		Color alphaRed = Color::ALPHA_RED;
		typedef Element::cpoint_list::const_iterator iterator;
		for (iterator it = element.getConnectionPoints().begin(); it != element.getConnectionPoints().end(); ++it) {
			double x = (*it)->getPosition().getX();
			double y = (*it)->getPosition().getY();

			drawingContext->save();
			if ((*it)->isConnected()) {
				drawingContext->set_source_rgba(alphaBlue.getRed(),
						alphaBlue.getGreen(), alphaBlue.getBlue(), alphaBlue.getAlpha());
			} else {
				drawingContext->set_source_rgba(alphaRed.getRed(),
						alphaRed.getGreen(), alphaRed.getBlue(), alphaRed.getAlpha());
			}
			drawingContext->arc(x, y, (*it)->getRadius(), 0, 2 * M_PI);
			drawingContext->fill();
			drawingContext->restore();
		}
	}
}

