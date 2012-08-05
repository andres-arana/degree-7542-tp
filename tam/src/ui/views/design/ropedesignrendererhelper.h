#ifndef __UI__VIEWS__DESIGN__ROPEDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__ROPEDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/rope.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar sogas
			 */
			class RopeDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de RopeDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				RopeDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja una soga
				 * @param rope Soga a dibujar
				 */
				void renderRope(const game::design::elements::Rope &rope) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
