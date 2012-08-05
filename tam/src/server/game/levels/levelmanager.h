#ifndef SERVER_GAME_LEVELS_LEVELMANAGER_H_
#define SERVER_GAME_LEVELS_LEVELMANAGER_H_

#include "level.h"
#include <vector>

namespace server {
	namespace game {
		namespace levels {
			/**
			 * Administrador de Niveles.
			 * @author Gabriel Raineri
			 */
			class LevelManager {
				private:
					static std::string LEVELS_FOLDER;
					std::vector<int> shuffledLevels;
					size_t currentLevelPos;
					int timesSent;
					
					void setUpLevels();
					
				public:
					LevelManager();					
					/**
					 * Prepara el siguiente nivel para ser devuelto. 
					 */
					void prepareNextLevel();					
					/**
					 * Devuelve el nivel actual.
					 * @return El nivel actual.
					 */
					Level getCurrentLevel() const;
					/**
					 * Marca el nivel actual como enviado.
					 */
					void markCurrentLevelAsSent();
					/**
					 * Devuelve la cantidad de veces que fue enviado el nivel actual.
					 * @return La cantidad de veces que fue enviado el nivel actual.
					 */
					int getLevelTimesSent() const;
			};
		}
	}
}

#endif /*SERVER_GAME_LEVELS_LEVELMANAGER_H_*/
