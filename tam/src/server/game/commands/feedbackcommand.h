#ifndef SERVER_GAME_COMMANDS_FEEDBACKCOMMAND_H_
#define SERVER_GAME_COMMANDS_FEEDBACKCOMMAND_H_

#include "command.h"

namespace server {
	namespace game {
		namespace commands {
			/**
			 * Comando para enviar lo que un oponente esta diseniando al resto de los
			 * jugadores.
			 * @author Gabriel Raineri
			 */
			class FeedbackCommand : public Command {
				public:					
					virtual void execute(server::game::client::GameClient* gameClient, 
			    		const std::string& params);
			};		
		}
	}
}

#endif /*SERVER_GAME_COMMANDS_FEEDBACKCOMMAND_H_*/
