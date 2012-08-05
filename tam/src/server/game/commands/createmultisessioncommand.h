#ifndef SERVER_GAME_COMMANDS_CREATEMULTISESSIONCOMMAND_H_
#define SERVER_GAME_COMMANDS_CREATEMULTISESSIONCOMMAND_H_

#include "command.h"

namespace server {
	namespace game {
		namespace commands {
			/**
			 * Comando para la creacion de sesiones de varios jugador.
			 * @author Gabriel Raineri
			 */
			class CreateMultiSessionCommand : public Command {
				public:					
					virtual void execute(server::game::client::GameClient* gameClient, 
			    		const std::string& params);
			};		
		}
	}
}

#endif /*SERVER_GAME_COMMANDS_CREATEMULTISESSIONCOMMAND_H_*/
