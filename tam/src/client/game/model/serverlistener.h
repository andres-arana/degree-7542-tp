#ifndef CLIENT_GAME_MODEL_SERVERLISTENER_H_
#define CLIENT_GAME_MODEL_SERVERLISTENER_H_

#include "threads/thread.h"
#include "protocol/protocolreceiver.h"

namespace client {
	namespace game {
		namespace model {
			class GameClient; 
			/**
			 * Listener para los mensajes enviados del Game Server.
			 * @author Gabriel Raineri
			 */
			class ServerListener : public common::threads::Thread {
				private:
					GameClient* gameClient;
					common::protocol::ProtocolReceiver protocolReceiver;
					
					void parseResponse(const std::string& response); 
					
				protected:
					virtual void run();
				
				public:
					/**
					 * Constructor.
					 */
					ServerListener(GameClient* gameClient);
					/**
					 * Destructor.
					 */
					virtual ~ServerListener();
			};			
		}
	}
}

#endif /*CLIENT_GAME_MODEL_SERVERLISTENER_H_*/
