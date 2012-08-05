#ifndef SERVER_GAME_CLIENT_MESSAGEPOOL_H_
#define SERVER_GAME_CLIENT_MESSAGEPOOL_H_

#include <list>
#include <string>
#include <vector>
#include "threads/locks/mutex.h"
#include "threads/locks/conditionalwait.h"
#include "sockets/data.h"

namespace server {
	namespace game {
		namespace client {
			
			class MessagePool {
				private:
					std::list<common::sockets::Data*> messagePool;					
					common::threads::locks::Mutex mutex;
					common::threads::locks::ConditionalWait* condWait;
					
				public:
					MessagePool();
					~MessagePool();
					
					void addMessage(const std::string& message);
					void addMessage(common::sockets::Data* message);
					std::vector<common::sockets::Data*>* getAllMessages();
					void setConditionalWait(
							common::threads::locks::ConditionalWait* condWait);
					void releaseConditionalWait();							
			};			
		}
	}
}

#endif /*SERVER_GAME_CLIENT_MESSAGEPOOL_H_*/
