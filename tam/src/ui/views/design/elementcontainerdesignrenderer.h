#ifndef __UI__VIEWS__DESIGN__ELEMENTCONTAINERDESIGNRENDERER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__ELEMENTCONTAINERDESIGNRENDERER_H_INCLUDED__

#include "../renderer.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Implementacion de Renderer que dibuja los elementos
			 * en tiempo de diseño.
			 */
			class ElementContainerDesignRenderer : public Renderer {
			public:
				/**
				 * Crea una nueva instancia de ElementContainerDesignRenderer
				 * @param container Contenedor que tiene los elementos
				 * a dibujar
				 */
				ElementContainerDesignRenderer(const game::design::ElementContainer &container);

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
