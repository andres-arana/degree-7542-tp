#ifndef CLIENT_GAME_COMMANDS_MESSAGECOMMAND_H_
#define CLIENT_GAME_COMMANDS_MESSAGECOMMAND_H_

#include "command.h"

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Comando para enviar y recibir mensajes.
			 * @author Gabriel Raineri
			 */
			class MessageCommand : public Command {
				public:										
					virtual std::string buildRequest() const;
			    		
			    virtual void executeResponse(
			    		client::game::model::GameClient* gameClient);
			};			 
		}
	}
}

#endif /*CLIENT_GAME_COMMANDS_MESSAGECOMMAND_H_*/
