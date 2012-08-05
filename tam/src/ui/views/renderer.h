#ifndef __UI__VIEWS__RENDERER_H_INCLUDED__
#define __UI__VIEWS__RENDERER_H_INCLUDED__

#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		/**
		 * Representa un objeto capaz de dibujar sobre una superficie
		 * Cairo, como puede ser la utilizada por GameRenderArea
		 */
		class Renderer {
		public:
			virtual void render(Cairo::RefPtr<Cairo::Context> drawingContext) const = 0;

			virtual ~Renderer() {};
		};
	}
}

#endif
