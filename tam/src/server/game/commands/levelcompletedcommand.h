#ifndef SERVER_GAME_COMMANDS_LEVELCOMPLETEDCOMMAND_H_
#define SERVER_GAME_COMMANDS_LEVELCOMPLETEDCOMMAND_H_

#include "command.h"

namespace server {
	namespace game {
		namespace commands {
			/**
			 * Comando cuyo objetivo es marcar un nivel como completado.
			 * @author Gabriel Raineri
			 */
			class LevelCompletedCommand : public Command {
				public:
			    virtual void execute(server::game::client::GameClient* gameClient, 
			    		const std::string& params);	
			};
		}
	}
}
#endif /*SERVER_GAME_COMMANDS_LEVELCOMPLETEDCOMMAND_H_*/
