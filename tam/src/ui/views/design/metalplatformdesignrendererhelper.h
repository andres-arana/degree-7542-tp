#ifndef __UI__VIEWS__DESIGN__METALPLATFORMDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__METALPLATFORMDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/metalplatform.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar plataformas metalicas
			 */
			class MetalPlatformDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de MetalPlatformDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				MetalPlatformDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja una plataforma metalica
				 * @param platform Plataforma metalica a dibujar
				 */
				void renderMetalPlatform(const game::design::elements::MetalPlatform &platform) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
