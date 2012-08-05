#ifndef __UI__CONTROLLERS__CONFIGURABLERENDERAREACONTROLLER_H_INCLUDED__
#define __UI__CONTROLLERS__CONFIGURABLERENDERAREACONTROLLER_H_INCLUDED__

#include "../views/gamerenderarea.h"
#include "renderareainputhandler.h"

namespace ui {
	namespace controllers {
		/**
		 * Controlador configurable que delega el
		 * manejo del input del usuario a un stragegy
		 * interno. Permite manejar los diferentes
		 * modos de edicion de un GameRenderArea
		 */
		class ConfigurableRenderAreaController {
		public:
			/**
			 * Crea una nueva instancia de ConfigurableRenderAreaController
			 * @param renderAreaWidget Render area cuyo input de usuario
			 * se estará controlando
			 */
			ConfigurableRenderAreaController(ui::views::GameRenderArea &renderAreaWidget);

			/**
			 * Establece un nuevo strategy de manejo de input de usuario.
			 * El lifecycle del handler configurado es manejado por
			 * el controlador, por lo que no es necesario guardar una
			 * referencia a el.
			 * @param handler Strategy a configurar
			 */
			void configureCurrentHandler(RenderAreaInputHandler *handler);

			~ConfigurableRenderAreaController();
		private:
			void onMousePressed(int x, int y);
			void onMouseReleased(int x, int y);
			void onMouseMotion(int x, int y);

			RenderAreaInputHandler *currentHandler;
			ui::views::GameRenderArea &renderArea;
		};
	}
}

#endif
