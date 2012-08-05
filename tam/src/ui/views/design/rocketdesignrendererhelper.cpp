#include "rocketdesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

RocketDesignRendererHelper::RocketDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void RocketDesignRendererHelper::renderRocket(const Rocket &rocket) const {
	if (rocket.isErased()) return;
	Color white = Color::WHITE;

	drawingContext->save();
	drawingContext->set_source_rgb(white.getRed(), white.getGreen(),
			white.getBlue());
	drawingContext->arc(rocket.getPosition().getX(), rocket.getPosition().getY(), rocket.getBodyRadius(), 0, 2 * M_PI);
	drawingContext->fill();
	drawingContext->move_to(rocket.getPosition().getX(), rocket.getPosition().getY());
	drawingContext->line_to(rocket.getTarget().getX(), rocket.getTarget().getY());
	drawingContext->stroke();

	drawingContext->restore();
}

