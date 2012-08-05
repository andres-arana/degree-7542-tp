#ifndef SERVER_GAME_CLIENT_MESSAGERECEIVER_H_
#define SERVER_GAME_CLIENT_MESSAGERECEIVER_H_

#include <string>
#include "threads/thread.h"

namespace server {
	namespace game {
		namespace client {
			
			class GameClient;
			
			/**
			 * Clase encargada de la recepcion de mensajes.
			 * @author Gabriel Raineri
			 */
			class MessageReceiver : public common::threads::Thread {
				private:
					GameClient* gameClient;
					void processMessage(const std::string& message);
					bool hasToShutdown;
					 
				protected:
					virtual void run();
					
				public:
					/**
					 * Constructor.
					 */
					MessageReceiver(GameClient* gameClient);
					/**
					 * Destructor.
					 */
					virtual ~MessageReceiver();
					/**
					 * Establece si se debe cerrar.
					 */
					void setHasToShutdown(bool shutdown);
			};
		}
	}
}
#endif /*SERVER_GAME_CLIENT_MESSAGERECEIVER_H_*/
