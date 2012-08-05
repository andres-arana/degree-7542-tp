#ifndef SERVER_GAME_COMMANDS_COMMAND_H_
#define SERVER_GAME_COMMANDS_COMMAND_H_

#define MSG_RESPONSE_CMD "/msg "
#define REC_SEPARATOR '\30' // Record Separator

#include <string>
#include "../client/gameclient.h"

namespace server {
	namespace game {
		namespace commands {
			/**
			 * Interfaz para Comandos.
			 * @author Gabriel Raineri
			 */
			class Command {    			    
			  public:
			  	Command() {}
			    virtual ~Command() {}		     
			    
			    virtual void execute(server::game::client::GameClient* gameClient, 
			    		const std::string& params = "") = 0;
			};
		}
	}
}

#endif /*SERVER_GAME_COMMANDS_COMMAND_H_*/
