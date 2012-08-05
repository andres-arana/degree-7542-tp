#ifndef SERVER_GAME_COMMANDS_AVAILABLESESSIONSCOMMAND_H_
#define SERVER_GAME_COMMANDS_AVAILABLESESSIONSCOMMAND_H_

#include "command.h"

namespace server {
	namespace game {
		namespace commands {
			/**
			 * Comando cuyo objetivo es enviar las sesiones disponibles a un jugador.
			 * @author Gabriel Raineri
			 */
			class AvailableSessionsCommand : public Command {
				public:
			    virtual void execute(server::game::client::GameClient* gameClient, 
			    		const std::string& params);				

			};
		}
	}
}


#endif /*SERVER_GAME_COMMANDS_AVAILABLESESSIONSCOMMAND_H_*/
