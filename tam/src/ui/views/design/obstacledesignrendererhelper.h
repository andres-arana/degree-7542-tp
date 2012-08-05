#ifndef __UI__VIEWS__DESIGN__OBSTACLEDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__OBSTACLEDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/obstacle.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar obstaculos
			 */
			class ObstacleDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de ObstacleDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				ObstacleDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja un obstaculo
				 * @param obstacle Obstaculo a dibujar
				 */
				void renderObstacle(const game::design::elements::Obstacle &obstacle) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
