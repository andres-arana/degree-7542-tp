#include "backgroundrenderer.h" 
#include <gtkmm.h>

using namespace ui::views;
using namespace std;

BackgroundRenderer::BackgroundRenderer(const string& filename) {
	this->pixBuf = Gdk::Pixbuf::create_from_file(filename);    
  Cairo::Format format = Cairo::FORMAT_ARGB32;	
	this->imageSurface = Cairo::ImageSurface::create(
			format, pixBuf->get_width(), pixBuf->get_height());    
}

void BackgroundRenderer::render(
		Cairo::RefPtr<Cairo::Context> drawingContext) const {
	
	double x1, x2, y1, y2;
	drawingContext->save();
	drawingContext->get_clip_extents(x1, y1, x2, y2);
	Gdk::Cairo::set_source_pixbuf(drawingContext, this->pixBuf->scale_simple(
			(x2 - x1), (y2 - y1), Gdk::INTERP_BILINEAR), 0, 0);
	drawingContext->paint_with_alpha(0.4);
	drawingContext->restore();
}

