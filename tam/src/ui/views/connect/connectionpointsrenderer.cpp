#include "connectionpointsrenderer.h"
#include "connectionpointrendererhelper.h"

using namespace Cairo;
using namespace ui::views;
using namespace ui::views::connect;
using namespace game::design;

ConnectionPointsRenderer::ConnectionPointsRenderer(const ElementContainer &container) :
	container(container) {

}

void ConnectionPointsRenderer::render(RefPtr<Context> drawingContext) const {
	ConnectionPointDesignRendererHelper renderer(drawingContext);
	const ElementContainer::ElementCollection &elements = container.getElementConstCollection();
	for (ElementContainer::ElementConstIterator it = elements.begin(); it != elements.end(); ++it) {
		renderer.renderConnectionPoints(**it);
	}
}

