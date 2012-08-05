#ifndef __UI__VIEWS__DESIGN__ELEMENTCONTAINERRUNTIMERENDERER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__ELEMENTCONTAINERRUNTIMERENDERER_H_INCLUDED__

#include "../renderer.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace views {
		namespace runtime {
			/**
			 * Implementacion de renderer que dibuja
			 * la representacion en tiempo de simulacion
			 * de los elementos
			 */
			class ElementContainerRuntimeRenderer : public Renderer {
			public:
				/**
				 * Crea una nueva instancia de ElementContainerRuntimeRenderer
				 * @param container Contenedor cuyos elementos seran
				 * dibujados
				 */
				ElementContainerRuntimeRenderer(const game::design::ElementContainer &container);

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
