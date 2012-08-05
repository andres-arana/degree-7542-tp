#ifndef SERVER_GAME_CLIENT_MESSAGESENDER_H_
#define SERVER_GAME_CLIENT_MESSAGESENDER_H_

#include <vector>
#include <string>
#include "threads/thread.h"
#include "threads/locks/conditionalwait.h"
#include "sockets/tcpsocket.h"
#include "sockets/data.h"
#include "protocol/protocolsender.h"
#include "messagepool.h"

namespace server {
	namespace game {
		namespace client {
			/**
			 * Clase encargada del envio de mensajes.
			 * @author Gabriel Raineri
			 */
			class MessageSender : public common::threads::Thread {
				private:
					MessagePool* messagePool;
					common::sockets::TcpSocket* clientSocket;
					common::protocol::ProtocolSender protocolSender;
					common::threads::locks::ConditionalWait* conditionalWait;
					
					void sendMessages(std::vector<common::sockets::Data*>* messages);
					void clearMessages(std::vector<common::sockets::Data*>* messages);
					
				protected:
					virtual void run();
					
				public:
					/**
					 * Constructor.
					 */	
					MessageSender(MessagePool* messagePool, 
							common::sockets::TcpSocket* clientSocket);
					/**
					 * Destructor.
					 */
					virtual ~MessageSender();
					/**
					 * {@inheritDocs}
					 */
					virtual void stop();
			};
		}
	}
}
#endif /*SERVER_GAME_CLIENT_MESSAGESENDER_H_*/
