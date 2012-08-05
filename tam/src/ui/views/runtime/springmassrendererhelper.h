#ifndef __UI__VIEWS__RUNTIME__SPRINGMASSRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__RUNTIME__SPRINGMASSRENDERERHELPER_H_INCLUDED__

#include "design/elements/element.h"
#include "../color.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace runtime {
			/**
			 * Helper encargado de dibujar las
			 * masas y los resortes de elementos
			 * construidos
			 */
			class SpringMassRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de SpringMassRendererHelper
				 * @param massColor Color con el que deben dibujarse las
				 * masas de los elementos
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				SpringMassRendererHelper(const Color &massColor, Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja las masas y los resortes de un elemento
				 * @param element Elemento a dibujar
				 */
				void renderElement(const game::design::elements::Element &element) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
				const Color& massColor;
			};
		}
	}
}

#endif
