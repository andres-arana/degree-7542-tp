#ifndef __UI_VIEWS__BLUEPRINTRENDERER_H_INCLUDED__
#define __UI_VIEWS__BLUEPRINTRENDERER_H_INCLUDED__

#include "renderer.h"

namespace ui {
	namespace views {
		/**
		 * Implementacion de Renderer que dibuja un fondo
		 * de un colo azul homogeneo
		 */
		class BlueprintRenderer : public Renderer {
		public:
			/**
			 * @see Renderer#render
			 */
			virtual void render(Cairo::RefPtr<Cairo::Context> drawingContext) const;
		};
	}
}

#endif
