#ifndef CLIENT_GAME_COMMANDS_FEEDBACKCOMMAND_H_
#define CLIENT_GAME_COMMANDS_FEEDBACKCOMMAND_H_

#include "command.h"

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Comando para crear sesiones single player.
			 * @author Gabriel Raineri
			 */
			class FeedbackCommand : public Command {
				public:						
					virtual std::string buildRequest() const;
			    		
			    virtual void executeResponse(
			    		client::game::model::GameClient* gameClient);
			};			 
		}
	}
}

#endif /*CLIENT_GAME_COMMANDS_FEEDBACKCOMMAND_H_*/
