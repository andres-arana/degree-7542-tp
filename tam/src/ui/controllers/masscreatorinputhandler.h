#ifndef __UI__CONTROLLERS__MASSCREATORINPUTHANDLER_H_INCLUDED__
#define __UI__CONTROLLERS__MASSCREATORINPUTHANDLER_H_INCLUDED__

#include "renderareainputhandler.h"
#include "design/elements/mass.h"
#include "design/elementfactory.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace controllers {
		/**
		 * Implementacion de RenderAreaInputHandler para manejar
		 * la creacion de masas en el area de diseño
		 */
		class MassCreatorInputHandler : public RenderAreaInputHandler {
		public:
			/**
			 * Crea una nueva instancia de MassCreatorInputHandler
			 * @param factory Implementacion de ElementFactory
			 * desde donde el controller obtendra los nuevos
			 * elementos
			 * @param container Implementacion de ElementContainer
			 * a donde el controller generará los nuevos elementos
			 */
			MassCreatorInputHandler(
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
			game::design::elements::Mass *mass;
			game::design::ElementFactory &factory;
			game::design::ElementContainer &container;
		};
	}
}

#endif
