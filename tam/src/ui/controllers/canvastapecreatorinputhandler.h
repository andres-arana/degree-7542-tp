#ifndef __UI__CONTROLLERS__CANVASTAPECREATORINPUTHANDLER_H_INCLUDED__
#define __UI__CONTROLLERS__CANVASTAPECREATORINPUTHANDLER_H_INCLUDED__

#include "renderareainputhandler.h"
#include "design/elements/canvastape.h"
#include "design/elementfactory.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace controllers {
		/**
		* Implementacion de RenderAreaInputHandler para manejar
		* la creacion de cintas de lona en el area de diseño
		*/
		class CanvasTapeCreatorInputHandler : public RenderAreaInputHandler {
		public:
			/**
			* Crea una nueva instancia de CanvasTapeCreatorInputHandler
			* @param factory Implementacion de ElementFactory
			* desde donde el controller obtendra los nuevos
			* elementos
			* @param container Implementacion de ElementContainer
			* a donde el controller generará los nuevos elementos
			*/
			CanvasTapeCreatorInputHandler(
					game::design::ElementFactory &factory,
					game::design::ElementContainer &container);

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
			game::design::elements::CanvasTape *canvasTape;
			game::design::ElementFactory &factory;
			game::design::ElementContainer &container;
		};
	}
}

#endif
