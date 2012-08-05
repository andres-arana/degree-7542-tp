#ifndef SERVER_GAME_COMMANDS_JOINCOMMAND_H_
#define SERVER_GAME_COMMANDS_JOINCOMMAND_H_

#include "command.h"

namespace server {
	namespace game {
		namespace commands {
			/**
			 * Comando cuyo objetivo es unir un cliente a una Sesion.
			 * @author Gabriel Raineri
			 */
			class JoinCommand : public Command {
				public:
			    virtual void execute(server::game::client::GameClient* gameClient, 
			    		const std::string& sessionIdStr);	
			};
		}
	}
}

#endif /*SERVER_GAME_COMMANDS_JOINCOMMAND_H_*/
