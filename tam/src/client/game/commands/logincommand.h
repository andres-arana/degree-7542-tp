#ifndef CLIENT_GAME_COMMANDS_LOGINCOMMAND_H_
#define CLIENT_GAME_COMMANDS_LOGINCOMMAND_H_

#include "command.h"

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Comando para loguearse en el servidor y verificar la respuesta.
			 * @author Gabriel Raineri
			 */
			class LoginCommand : public Command {
				public:						
					virtual std::string buildRequest() const;
			    		
			    virtual void executeResponse(
			    		client::game::model::GameClient* gameClient);
			};			 
		}
	}
}

#endif /*CLIENT_GAME_COMMANDS_LOGINCOMMAND_H_*/
