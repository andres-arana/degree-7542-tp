#ifndef SERVER_GAME_COMMANDS_LEVELCOMMAND_H_
#define SERVER_GAME_COMMANDS_LEVELCOMMAND_H_

#include "command.h"
#include "../levels/level.h"

namespace server {
	namespace game {
		namespace commands {
			/**
			 * Comando cuyo objetivo es enviar un nivel a la sesion.
			 * @author Gabriel Raineri
			 */
			class LevelCommand : public Command {
				private:
					/**
					 * Envia al cliente un archivo.
					 * @param gameClient El Cliente al cual se le enviara el archivo.
					 * @param path El path al archivo que sera enviado.
					 * @param fileLength La longitud del archivo.
					 */
					void sendFile(server::game::client::GameClient* gameClient, 
							const std::string& path, long fileLength); 
					/**
					 * Envia al cliente la cabecera del nivel.
					 * @param gameClient El cliente al cual se le enviara la cabecera.
					 * @param level El nivel cuya cabecera sera enviada.
					 */
					void sendLevelHeader(server::game::client::GameClient* gameClient, 
							const server::game::levels::Level& level);
					/**
					 * Envia al cliente el descriptor del nivel.
					 * @param gameclient El cliente al cual se le enviara el descriptor 
					 * 			del nivel.
					 * @param level El nivel cuyo descriptor sera enviado.
					 */
					void sendLevelDescriptor(server::game::client::GameClient* gameClient, 
							const server::game::levels::Level& level);
					/**
					 * Envia al cliente la imagen de fondo para el nivel.
					 * @param gameClient El cliente al cual se le enviara la imagen de 
					 * 			fondo del nivel.
					 * @param level El nivel cuya imagen de fondo sera enviada.
					 */
					void sendBackgroundImage(server::game::client::GameClient* gameClient, 
							const server::game::levels::Level& level);
				
				public:
			    virtual void execute(server::game::client::GameClient* gameClient, 
			    		const std::string& message);				

			};
		}
	}
}

#endif /*SERVER_GAME_COMMANDS_LEVELCOMMAND_H_*/
