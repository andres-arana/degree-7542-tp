#ifndef __UI__CONTROLLERS__RENDERAREAINPUTHANDLER_H_INCLUDED__
#define __UI__CONTROLLERS__RENDERAREAINPUTHANDLER_H_INCLUDED__

namespace ui {
	namespace controllers {
		/**
		 * Estrategia de manejo del input de usuario
		 * configurable dentro de un ConfigurableRenderAreaController
		 */
		class RenderAreaInputHandler {
		public:
			/**
			 * Ocurre cuando se presiona el botón izquierdo del
			 * mouse sobre el area de diseño
			 * @param x Posicion x del mouse cuando se hizo
			 * click
			 * @param y Posicion y del mouse cuando se hizo click
			 */
			virtual void handleMousePressed(int x, int y) = 0;

			/**
			 * Ocurre cuando se suelta el botón izquierdo del
			 * mouse sobre el area de diseño
			 * @param x Posicion x del mouse cuando se solto
			 * el click
			 * @param y Posicion y del mouse cuando se solto
			 * el click
			 */
			virtual void handleMouseRelease(int x, int y) = 0;

			/**
			 * Ocurre cuando se mueve el mouse sobre el
			 * area de diseño
			 * @param x Posicion x del mouse a la que se movio
			 * @param y Posicion y del mouse a la que se movio
			 */
			virtual void handleMouseMotion(int x, int y) = 0;

			virtual ~RenderAreaInputHandler() {};
		};
	}
}

#endif
