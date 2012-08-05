#ifndef __UI__CONTROLLERS__CONNECTINPUTHANDLER_H_INCLUDED__
#define __UI__CONTROLLERS__CONNECTINPUTHANDLER_H_INCLUDED__

#include "renderareainputhandler.h"
#include "../views/gamerenderarea.h"
#include "design/connect/connectionpoint.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace controllers {
		/**
		* Implementacion de RenderAreaInputHandler para manejar
		* la conexión de elemnetos en el area de diseño
		*/
		class ConnectInputHandler : public RenderAreaInputHandler {
		public:
			/**
			 * Crea una nueva instancia de ConnectInputHandler
			 * @param renderArea Render area sobre el que se
			 * estará trabajando
			 * @param container Contenedo donde se insertaran
			 * las conexiones y donde además están los
			 * objetos a conectar
			 */
			ConnectInputHandler(views::GameRenderArea &renderArea, game::design::ElementContainer &container);

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

			~ConnectInputHandler();
		private:
			views::GameRenderArea &renderArea;
			game::design::ElementContainer &container;
			game::design::connect::ConnectionPoint *firstPoint;
			game::design::connect::ConnectionPoint *secondPoint;
		};
	}
}

#endif
