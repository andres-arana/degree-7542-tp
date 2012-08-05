#include "movepointsrenderer.h"
#include "movepointrendererhelper.h"

using namespace Cairo;
using namespace ui::views;
using namespace ui::views::move;
using namespace game::design;

MovePointsRenderer::MovePointsRenderer(const ElementContainer &container) :
	container(container) {

}

void MovePointsRenderer::render(RefPtr<Context> drawingContext) const {
	MovePointDesignRendererHelper renderer(drawingContext);
	const ElementContainer::ElementCollection &elements = container.getElementConstCollection();
	for (ElementContainer::ElementConstIterator it = elements.begin(); it != elements.end(); ++it) {
		renderer.renderMovePoints(**it);
	}
}

