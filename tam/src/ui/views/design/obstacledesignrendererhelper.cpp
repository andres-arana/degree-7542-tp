#include "obstacledesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

ObstacleDesignRendererHelper::ObstacleDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void ObstacleDesignRendererHelper::renderObstacle(const Obstacle &obstacle) const {
	if (obstacle.isErased()) return;

	Color orange = Color::ORANGE;
	Vector2d ul = obstacle.getUpperLeftCorner();
	Vector2d ll = obstacle.getLowerLeftCorner();
	Vector2d lr = obstacle.getLowerRightCorner();
	Vector2d ur = obstacle.getUpperRightCorner();

	drawingContext->save();

	drawingContext->set_source_rgb(orange.getRed(), orange.getGreen(),
			orange.getBlue());
	drawingContext->move_to(ul.getX(), ul.getY());

	drawingContext->line_to(ll.getX(), ll.getY());
	drawingContext->line_to(lr.getX(), lr.getY());
	drawingContext->line_to(ur.getX(), ur.getY());
	drawingContext->line_to(ul.getX(), ul.getY());
	drawingContext->fill();

	drawingContext->restore();
}

