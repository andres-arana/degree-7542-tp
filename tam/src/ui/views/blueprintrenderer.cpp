#include "blueprintrenderer.h"

using namespace Cairo;
using namespace ui::views;

void BlueprintRenderer::render(RefPtr<Context> drawingContext) const {
	drawingContext->save();

	drawingContext->set_source_rgb(0.368627451, 0.494117647, 0.48627451);
	drawingContext->paint();

	drawingContext->restore();
}
