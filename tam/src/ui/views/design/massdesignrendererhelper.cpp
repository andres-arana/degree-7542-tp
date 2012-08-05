#include "massdesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

MassDesignRendererHelper::MassDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void MassDesignRendererHelper::renderMass(const Mass &mass) const {
	if (mass.isErased()) return;
	Color white = Color::WHITE;
	double x = mass.getPosition().getX();
	double y = mass.getPosition().getY();

	drawingContext->save();
	drawingContext->set_source_rgb(white.getRed(), white.getGreen(),
			white.getBlue());
	drawingContext->arc(x, y, mass.getRadius(), 0, 2 * M_PI);
	drawingContext->fill();
	drawingContext->restore();
}

