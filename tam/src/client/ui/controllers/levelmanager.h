#ifndef CLIENT_UI_CONTROLLERS_LEVELMANAGER_H_
#define CLIENT_UI_CONTROLLERS_LEVELMANAGER_H_

#include "logic/gameengine.h"
#include "views/gamerenderarea.h"
#include "serialization/businessdelegate.h"

namespace client {
	namespace ui {
		namespace controllers {
			class LevelManager {
				private:
					::game::logic::GameEngine& gameEngine;
					::ui::views::GameRenderArea& gameRenderArea;
					::game::serialization::BusinessDelegate serializationDelegate;

					void loadStage();
					void loadDesignRenderer();
					void loadRuntimeRenderer();
					void loadConnectionRenderer();
					void loadMoveRenderer();
					void loadBackgroundRenderer();

				public:
					LevelManager(::game::logic::GameEngine& gameEngine,
							::ui::views::GameRenderArea& gameRenderArea);

					void loadLevel();
			};
		}
	}
}

#endif /*CLIENT_UI_CONTROLLERS_LEVELMANAGER_H_*/
