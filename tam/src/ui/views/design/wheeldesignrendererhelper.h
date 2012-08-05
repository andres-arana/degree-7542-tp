#ifndef __UI__VIEWS__DESIGN__WHEELDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__WHEELDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/wheel.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar ruedas
			 */
			class WheelDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de WheelDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				WheelDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja una rueda
				 * @param wheel Rueda a dibujar
				 */
				void renderWheel(const game::design::elements::Wheel &wheel) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
