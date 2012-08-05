#ifndef __UI__VIEWS__MOVE__MOVEPOINTDESIGNRENDERERHELPER_H_INCLUDED__
#define __UI__VIEWS__MOVE__MOVEPOINTDESIGNRENDERERHELPER_H_INCLUDED__

#include "design/elements/element.h"
#include <gtkmm/drawingarea.h>

namespace ui {
	namespace views {
		namespace move {
			/**
			 * Helper encargado de dibujar todos los move
			 * points de los elementos
			 */
			class MovePointDesignRendererHelper {
			public:
				/**
				 * Crea una nueva instancia de MovePointDesignRendererHelper
				 * @param drawingContext Cairo drawing context sobre el que
				 * se dibujara
				 */
				MovePointDesignRendererHelper(Cairo::RefPtr<Cairo::Context> drawingContext);

				/**
				 * Dibuja todos los move points del elemento
				 * @param element Elemento cuyos move points
				 * seran dibujados
				 */
				void renderMovePoints(const game::design::elements::Element &element) const;
			private:
				Cairo::RefPtr<Cairo::Context> drawingContext;
			};
		}
	}
}

#endif
