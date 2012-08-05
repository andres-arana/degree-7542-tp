#ifndef __UI__VIEWS__DESIGN__EXITAREADESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__EXITAREADESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/exitarea.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar areas de salida
			 */
			class ExitAreaDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de ExitAreaDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				ExitAreaDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja un area de salida
				 * @param exitArea Area de salida a dibujar
				 */
				void renderExitArea(const game::design::elements::ExitArea &exitArea) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
