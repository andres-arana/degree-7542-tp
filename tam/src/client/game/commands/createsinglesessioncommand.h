#ifndef CLIENT_GAME_COMMANDS_CREATESINGLESESSIONCOMMAND_H_
#define CLIENT_GAME_COMMANDS_CREATESINGLESESSIONCOMMAND_H_

#include "command.h"

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Comando para crear sesiones single player.
			 * @author Gabriel Raineri
			 */
			class CreateSingleSessionCommand : public Command {
				public:						
					virtual std::string buildRequest() const;
			    		
			    virtual void executeResponse(
			    		client::game::model::GameClient* gameClient);
			};			 
		}
	}
}

#endif /*CLIENT_GAME_COMMANDS_CREATESINGLESESSIONCOMMAND_H_*/
