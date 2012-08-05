#ifndef __UI__VIEWS__DESIGN__METALBARDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__METALBARDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/metalbar.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar barras metalicas
			 */
			class MetalBarDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de MetalBarDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				MetalBarDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja un barra metalica
				 * @param bar Barra metalica a dibujar
				 */
				void renderMetalBar(const game::design::elements::MetalBar &bar) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
