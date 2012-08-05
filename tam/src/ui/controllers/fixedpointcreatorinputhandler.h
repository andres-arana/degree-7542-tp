#ifndef __UI__CONTROLLERS__FIXEDPOINTCREATORINPUTHANDLER_H_INCLUDED__
#define __UI__CONTROLLERS__FIXEDPOINTCREATORINPUTHANDLER_H_INCLUDED__

#include "renderareainputhandler.h"
#include "design/elements/fixedpoint.h"
#include "design/elementfactory.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace controllers {
		/**
		 * Implementacion de RenderAreaInputHandler para manejar
		 * la creacion de puntos fijos en el area de diseño
		 */
		class FixedPointCreatorInputHandler : public RenderAreaInputHandler {
		public:
			/**
			 * Crea una nueva instancia de FixedPointCreatorInputHandler
			 * @param factory Implementacion de ElementFactory
			 * desde donde el controller obtendra los nuevos
			 * elementos
			 * @param container Implementacion de ElementContainer
			 * a donde el controller generará los nuevos elementos
			 */
			FixedPointCreatorInputHandler(
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
			game::design::elements::FixedPoint *fixedPoint;
			game::design::ElementFactory &factory;
			game::design::ElementContainer &container;
		};
	}
}

#endif


