#ifndef __UI__VIEWS__DESIGN__CONNECTIONDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__DESIGN__CONNECTIONDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/connection.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace design {
			/**
			 * Helper encargado de dibujar
			 * conexiones
			 */
			class ConnectionDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de ConnectionDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				ConnectionDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja una conexion
				 * @param connection Conexion a dibujar
				 */
				void renderConnection(const game::design::elements::Connection &connection) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
