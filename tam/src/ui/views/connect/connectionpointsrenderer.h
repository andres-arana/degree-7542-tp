#ifndef __UI__VIEWS__CONNECT__CONNECTIONPOINTSRENDERER_H_INCLUDED__
#define __UI__VIEWS__CONNECT__CONNECTIONPOINTSRENDERER_H_INCLUDED__

#include "../renderer.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace views {
		namespace connect {
			/**
			 * Implementacion de Renderer que dibuja los puntos
			 * de conexion de todos los elementos de un container
			 */
			class ConnectionPointsRenderer : public Renderer {
			public:
				/**
				 * Crea una nueva instancia de ConnectionPointsRenderer
				 * @param container Contenedor que tiene los elementos
				 * cuyos puntos de conexion seran dibujados
				 */
				ConnectionPointsRenderer(const game::design::ElementContainer &container);

				/**
				 * @see Renderer#render
				 */
				virtual void render(Cairo::RefPtr<Cairo::Context> drawingContext) const;
			private:
				const game::design::ElementContainer &container;
			};
		}
	}
}

#endif
