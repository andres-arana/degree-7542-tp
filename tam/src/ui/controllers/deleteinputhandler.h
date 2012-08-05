#ifndef __UI__CONTROLLERS__DELETEINPUTHANDLER_H_INCLUDED__
#define __UI__CONTROLLERS__DELETEINPUTHANDLER_H_INCLUDED__

#include "renderareainputhandler.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace controllers {
		/**
		* Implementacion de RenderAreaInputHandler para manejar
		* la eliminacion de elemnetos en el area de diseño
		*/
		class DeleteInputHandler : public RenderAreaInputHandler {
		public:
			/**
			 * Crea una nueva instancia de DeleteInputHandler
			 * @param container Contenedor en donde estan los
			 * elementos a eliminar
			 */
			DeleteInputHandler(game::design::ElementContainer& container);

			/**
			 * @see RenderAreaInputHandler#handleMousePressed
			 */
			virtual void handleMousePressed(int x, int y);
			/**
			 * @see RenderAreaInputHandler#handleMouseRelease
			 */
			virtual void handleMouseRelease(int x, int y);
			/**
			 * @see RenderAreaInputHandler#handleMouseMotion
			 */
			virtual void handleMouseMotion(int x, int y);
		private:
			game::design::ElementContainer &container;
		};
	}
}

#endif
