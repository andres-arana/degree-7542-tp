#ifndef SERVER_GAME_COMMANDS_MESSAGECOMMAND_H_
#define SERVER_GAME_COMMANDS_MESSAGECOMMAND_H_

#include <string>
#include "command.h"

namespace server {
	namespace game {
		namespace commands {

			class MessageCommand : public Command {
			  public:
			    virtual void execute(server::game::client::GameClient* gameClient, 
			    		const std::string& message);
			};
		}
	}
}

#endif /*SERVER_GAME_COMMANDS_MESSAGECOMMAND_H_*/
