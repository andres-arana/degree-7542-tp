#ifndef __UI__VIEWS__CONNECT__CONNECTIONPOINTDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__CONNECT__CONNECTIONPOINTDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/element.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace connect {
			/**
			 * Helper encargado de dibujar los connection points
			 * de un elemento en particular
			 */
			class ConnectionPointDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de ConnectionPointDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				ConnectionPointDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja todos los connection points de un elemento en particular
				 * @param element
				 */
				void renderConnectionPoints(const game::design::elements::Element &element) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
