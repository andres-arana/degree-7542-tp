#ifndef CLIENT_GAME_COMMANDS_COMMAND_H_
#define CLIENT_GAME_COMMANDS_COMMAND_H_

#include "../model/gameclient.h"
#include <string>

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Interfaz para Comandos.
			 * @author Gabriel Raineri
			 */
			class Command {
				protected:
					std::string params;
					
			  public:   
			    Command();
			    virtual ~Command();			   
			    
			    virtual void setParams(const std::string& params);
			            
			    virtual std::string buildRequest() const = 0;
			    virtual void executeResponse(
			    		client::game::model::GameClient* gameClient) = 0;
			};
		}
	}
}


#endif /*CLIENT_GAME_COMMANDS_COMMAND_H_*/
