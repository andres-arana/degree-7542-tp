#ifndef SERVER_GAME_LEVELS_LEVEL_H_
#define SERVER_GAME_LEVELS_LEVEL_H_

#include <string>

namespace server {
	namespace game {
		namespace levels {
			/**
			 * Nivel del Juego.
			 * @author Gabriel Raineri
			 */
			class Level {
				private:
					std::string levelFilePath;
					std::string backgroundFilePath;
					int number;									
					
				public:
					Level(const std::string& levelFolder, int number);					
					/**
					 * Retorna el numero de nivel.
					 * @return El numero de nivel.
					 */
					int getLevelNumber() const;
					
					/**
					 * Retorna la longitud del archivo de nivel.
					 * @return La longitud del archivo de nivel.
					 */
					long getLevelFileSize() const;
					/**
					 * Retorna el path al archivo de nivel.
					 * @return El path al archivo de nivel.
					 */
					const std::string& getLevelFilePath() const; 
					
					/**
					 * Retorna la longitud de la imagen de fondo del nivel.
					 * @return La longitud de la imagen de fondo del nivel.
					 */
					long getLevelBackgroundSize() const;
					/**
					 * Retorna el path a la imagen de fondo del nivel.
					 * @return El path a la imagen de fondo del nivel.
					 */
					const std::string& getLevelBackgroundPath() const;					
			};
		}
	}
}
#endif /*SERVER_GAME_LEVELS_LEVEL_H_*/
