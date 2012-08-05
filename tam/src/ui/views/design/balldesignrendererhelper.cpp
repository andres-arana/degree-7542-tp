#include "balldesignrendererhelper.h"
#include "../color.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::design;

BallDesignRendererHelper::BallDesignRendererHelper(RefPtr<Context> drawingContext) :
	drawingContext(drawingContext) {

}

void BallDesignRendererHelper::renderBall(const Ball &ball) const {
	if (ball.isErased()) return;

	Color goldColor = Color::GOLD;
	double x = ball.getPosition().getX();
	double y = ball.getPosition().getY();

	drawingContext->save();
	drawingContext->set_source_rgb(goldColor.getRed(), goldColor.getGreen(),
			goldColor.getBlue());
	drawingContext->arc(x, y, ball.getRadius(), 0, 2 * M_PI);
	drawingContext->fill();
	drawingContext->restore();
}
