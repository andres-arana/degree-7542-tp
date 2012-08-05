#ifndef __UI__VIEWS__DESIGN__FIXEDPOINTDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__FIXEDPOINTDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/fixedpoint.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar puntos fijos
			 */
			class FixedPointDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de FixedPointDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				FixedPointDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja un punto fijo
				 * @param fixedPoint Punto fijo a dibujar
				 */
				void renderFixedPoint(const game::design::elements::FixedPoint &fixedPoint) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
