#ifndef __UI__VIEWS__CONNECT__MOVEPOINTSRENDERER_H_INCLUDED__
#define __UI__VIEWS__CONNECT__MOVEPOINTSRENDERER_H_INCLUDED__

#include "../renderer.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace views {
		namespace move {
			/**
			 * Implementacion de Renderer que dibuja todos los
			 * move points de todos los elementos de un contenedor
			 */
			class MovePointsRenderer : public Renderer {
			public:
				/**
				 * Crea una nueva instancia de MovePointsRenderer
				 * @param container Contenedor cuyos elementos
				 * seran inspeccionados para dibujar sus move
				 * points
				 */
				MovePointsRenderer(const game::design::ElementContainer &container);

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

#endif /*__UI__VIEWS__CONNECT__MOVEPOINTSRENDERER_H_INCLUDED__*/
