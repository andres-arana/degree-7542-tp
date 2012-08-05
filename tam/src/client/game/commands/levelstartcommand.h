#ifndef CLIENT_GAME_COMMANDS_LEVELSTARTCOMMAND_H_
#define CLIENT_GAME_COMMANDS_LEVELSTARTCOMMAND_H_

#include "command.h"

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Comando que indica la senial de inicio de un juego.
			 * @author Gabriel Raineri
			 */
			class LevelStartCommand : public Command {
				public:					
					virtual std::string buildRequest() const;
			    		
			    virtual void executeResponse(
			    		client::game::model::GameClient* gameClient);
			};
		}
	}
}

#endif /*CLIENT_GAME_COMMANDS_LEVELSTARTCOMMAND_H_*/
