#ifndef CLIENT_GAME_COMMANDS_LEVELCOMPLETEDCOMMAND_H_
#define CLIENT_GAME_COMMANDS_LEVELCOMPLETEDCOMMAND_H_

#include "command.h"

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Comando para indicarle al servidor que el jugador ha finalizado un 
			 * nivel.
			 * @author Gabriel Raineri
			 */
			class LevelCompletedCommand : public Command {
				public:						
					virtual std::string buildRequest() const;
			    		
			    virtual void executeResponse(
			    		client::game::model::GameClient* gameClient);
			};			 
		}
	}
}

#endif /*CLIENT_GAME_COMMANDS_LEVELCOMPLETEDCOMMAND_H_*/
