#ifndef CLIENT_GAME_COMMNDS_JOINCOMMAND_H_
#define CLIENT_GAME_COMMNDS_JOINCOMMAND_H_

#include "command.h"

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Comando para unirse a sesiones multiplayer.
			 * @author Gabriel Raineri
			 */
			class JoinCommand : public Command {
				public:
					virtual std::string buildRequest() const;
			    		
			    virtual void executeResponse(
			    		client::game::model::GameClient* gameClient);
			};			 
		}
	}
}

#endif /*CLIENT_GAME_COMMNDS_JOINCOMMAND_H_*/
