#ifndef __UI__CONTROLLERS__BALLCREATORINPUTHANDLER_H_INCLUDED__
#define __UI__CONTROLLERS__BALLCREATORINPUTHANDLER_H_INCLUDED__

#include "renderareainputhandler.h"
#include "design/elements/ball.h"
#include "design/elementfactory.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace controllers {
		/**
		 * Implementacion de RenderAreaInputHandler para manejar
		 * la creacion de pelotas en el area de diseño
		 */
		class BallCreatorInputHandler : public RenderAreaInputHandler {
		public:
			/**
			 * Crea una nueva instancia de BallCreatorInputHandler
			 * @param factory Implementacion de ElementFactory
			 * desde donde el controller obtendra los nuevos
			 * elementos
			 * @param container Implementacion de ElementContainer
			 * a donde el controller generará los nuevos elementos
			 */
			BallCreatorInputHandler(
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
			game::design::elements::Ball *ball;
			game::design::ElementFactory &factory;
			game::design::ElementContainer &container;
		};
	}
}

#endif
