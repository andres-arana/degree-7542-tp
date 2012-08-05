#ifndef __UI__VIEWS__DESIGN__MASSDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__MASSDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/mass.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar masas
			 */
			class MassDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de MassDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				MassDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja una masa
				 * @param mass Masa a dibujar
				 */
				void renderMass(const game::design::elements::Mass &mass) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
