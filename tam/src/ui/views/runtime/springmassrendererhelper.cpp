#include "springmassrendererhelper.h"

using namespace Cairo;
using namespace game::core;
using namespace game::design::elements;
using namespace ui::views;
using namespace ui::views::runtime;

SpringMassRendererHelper::SpringMassRendererHelper(const Color &massColor, RefPtr<Context> drawingContext) :
	drawingContext(drawingContext),
	massColor(massColor) {

}

void SpringMassRendererHelper::renderElement(const Element &element) const {
	typedef std::vector<Spring *>::const_iterator s_iter;
	typedef std::vector<Particle *>::const_iterator p_iter;

	Color white = Color::WHITE;
	// Dibujo los resortes
	for (s_iter it = element.getSprings().begin(); it != element.getSprings().end(); ++it) {
		Vector2d from = (*it)->getFirst().getPosition();
		Vector2d to = (*it)->getSecond().getPosition();

		drawingContext->save();
		drawingContext->set_source_rgb(white.getRed(), white.getGreen(),
				white.getBlue());
		drawingContext->move_to(from.getX(), from.getY());
		drawingContext->line_to(to.getX(), to.getY());
		drawingContext->stroke();
		drawingContext->restore();
	}
	// Dibujo las masas
	for (p_iter it = element.getParticles().begin(); it != element.getParticles().end(); ++it) {
		Vector2d pos = (*it)->getPosition();

		drawingContext->save();
		drawingContext->arc(pos.getX(), pos.getY(), (*it)->getRadius(), 0.0, 2.0 * M_PI); // full circle

		drawingContext->set_source_rgba(massColor.getRed(), massColor.getGreen(),
				massColor.getBlue(), massColor.getAlpha());
		drawingContext->fill();
		drawingContext->restore();
	}
}
