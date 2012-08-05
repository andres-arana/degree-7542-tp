#ifndef CLIENT_GAME_COMMANDS_AVAILABLESESSIONSCOMMAND_H_
#define CLIENT_GAME_COMMANDS_AVAILABLESESSIONSCOMMAND_H_

#include <list>
#include "command.h"
#include "../model/session.h"

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Comando para unirse a sesiones multiplayer.
			 * @author Gabriel Raineri
			 */
			class AvailableSessionsCommand : public Command {
				private:
					std::list<client::game::model::Session*>* parseSessionList();
					
				public:
					virtual std::string buildRequest() const;
			    		
			    virtual void executeResponse(
			    		client::game::model::GameClient* gameClient);
			};			 
		}
	}
}

#endif /*CLIENT_GAME_COMMANDS_AVAILABLESESSIONSCOMMAND_H_*/
