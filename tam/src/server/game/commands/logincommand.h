#ifndef SERVER_GAME_COMMANDS_LOGINCOMMAND_H_
#define SERVER_GAME_COMMANDS_LOGINCOMMAND_H_

#include "command.h"

namespace server {
	namespace game {
		namespace commands {
			/**
			 * Comando cuyo objetivo es el login de un jugador en el servidor.
			 * @author Gabriel Raineri
			 */
			class LoginCommand : public Command {
				public:
			    virtual void execute(server::game::client::GameClient* gameClient, 
			    		const std::string& loginName);
			};
		}
	}
}

#endif /*SERVER_GAME_COMMANDS_LOGINCOMMAND_H_*/
