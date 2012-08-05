#ifndef __UI__VIEWS__DESIGN__ROCKETDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__ROCKETDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/rocket.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar cohetes
			 */
			class RocketDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de RocketDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				RocketDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja un cohete
				 * @param rocket Cohete a dibujar
				 */
				void renderRocket(const game::design::elements::Rocket &rocket) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
