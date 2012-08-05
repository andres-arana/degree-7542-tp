#include "metalplatformdesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

MetalPlatformDesignRendererHelper::MetalPlatformDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void MetalPlatformDesignRendererHelper::renderMetalPlatform(const MetalPlatform &platform) const {
	if (platform.isErased()) return;

	Color white = Color::WHITE;
	Vector2d ul = platform.getUpperLeftCorner();
	Vector2d ll = platform.getLowerLeftCorner();
	Vector2d lr = platform.getLowerRightCorner();
	Vector2d ur = platform.getUpperRightCorner();

	drawingContext->save();

	drawingContext->set_source_rgb(white.getRed(), white.getGreen(),
			white.getBlue());
	drawingContext->move_to(ul.getX(), ul.getY());

	drawingContext->line_to(ll.getX(), ll.getY());
	drawingContext->line_to(lr.getX(), lr.getY());
	drawingContext->line_to(ur.getX(), ur.getY());
	drawingContext->line_to(ul.getX(), ul.getY());
	drawingContext->fill();

	drawingContext->restore();
}

