#ifndef __UI__VIEWS__DESIGN__CANVASTAPEDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__CANVASTAPEDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/canvastape.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar una
			 * cinta de lona
			 */
			class CanvasTapeDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de CanvasTapeDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				CanvasTapeDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja una cinta de lona
				 * @param canvasTape Cinta de lona a dibujar
				 */
				void renderCanvasTape(const game::design::elements::CanvasTape &canvasTape) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
