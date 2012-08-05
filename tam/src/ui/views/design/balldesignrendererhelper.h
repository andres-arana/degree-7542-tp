#ifndef __UI__VIEWS__DESIGN__BALLDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__BALLDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/ball.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar una pelota en
			 * tiempo de diseño.
			 */
			class BallDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de BallDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				BallDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja una pelota
				 * @param ball Pelota a dibujar
				 */
				void renderBall(const game::design::elements::Ball &ball) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
