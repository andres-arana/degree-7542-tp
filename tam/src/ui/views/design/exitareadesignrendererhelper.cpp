#include "exitareadesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

ExitAreaDesignRendererHelper::ExitAreaDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void ExitAreaDesignRendererHelper::renderExitArea(const ExitArea &exitArea) const {
	if (exitArea.isErased()) return;

	Color lightBlue = Color::ALPHA_LIGHT_BLUE;
	double x = exitArea.getPosition().getX();
	double y = exitArea.getPosition().getY();

	drawingContext->save();
	drawingContext->set_source_rgba(lightBlue.getRed(), lightBlue.getGreen(),
			lightBlue.getBlue(), lightBlue.getAlpha());
	drawingContext->arc(x, y, exitArea.getRadius(), 0, 2 * M_PI);
	drawingContext->fill();
	drawingContext->restore();
}

