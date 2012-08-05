#include "connectiondesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

ConnectionDesignRendererHelper::ConnectionDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void ConnectionDesignRendererHelper::renderConnection(const Connection &connection) const {
	if (connection.isErased()) return;
	Color alphaBlue = Color::ALPHA_BLUE;
	drawingContext->save();
	drawingContext->set_line_width(connection.getConnectionWidth());
	drawingContext->set_source_rgba(alphaBlue.getRed(),
			alphaBlue.getGreen(), alphaBlue.getBlue(), alphaBlue.getAlpha());
	drawingContext->move_to(connection.getStartPosition().getX(), connection.getStartPosition().getY());

	drawingContext->line_to(connection.getEndPosition().getX(), connection.getEndPosition().getY());

	drawingContext->stroke();
	drawingContext->restore();
}

