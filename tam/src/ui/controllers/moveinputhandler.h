#ifndef __UI__CONTROLLERS__MOVEINPUTHANDLER_H_INCLUDED__
#define __UI__CONTROLLERS__MOVEINPUTHANDLER_H_INCLUDED__

#include "renderareainputhandler.h"
#include "../views/gamerenderarea.h"
#include "design/move/movepoint.h"
#include "design/elementcontainer.h"

namespace ui {
	namespace controllers {
		/**
		* Implementacion de RenderAreaInputHandler para manejar
		* el mover elementos en el area de diseño
		*/
		class MoveInputHandler : public RenderAreaInputHandler {
		public:
			/**
			 * Crea una nueva instancia de MoveInputHandler
			 * @param renderArea Render area sobre el que se
			 * estará trabajando
			 * @param container Contenedo donde se insertaran
			 * las conexiones y donde además están los
			 * objetos a conectar
			 */
			MoveInputHandler(views::GameRenderArea &renderArea, game::design::ElementContainer &container);

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

			~MoveInputHandler();
		private:
			views::GameRenderArea &renderArea;
			game::design::ElementContainer &container;
			game::design::move::MovePoint *selectedMovePoint;
		};
	}
}

#endif
