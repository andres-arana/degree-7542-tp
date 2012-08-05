#ifndef CLIENT_GAME_MODEL_REQUESTSENDER_H_
#define CLIENT_GAME_MODEL_REQUESTSENDER_H_

#include <vector>
#include "threads/thread.h"
#include "sockets/tcpsocket.h"
#include "protocol/protocolsender.h"

namespace client {
	namespace game {
		namespace commands {
			class Command;
		}
		namespace model {					
			/**
			 * Envio de Requests al Game Server.
			 * @author Gabriel Raineri
			 */
			class RequestSender : public common::threads::Thread {
				private:
					common::protocol::ProtocolSender protocolSender;
					common::sockets::TcpSocket* tcpSocket;
					void clearRequests(std::vector<const commands::Command*>* requests);
					void executeRequests(std::vector<const commands::Command*>* requests);
					
				protected:
					virtual void run();
					
				public:
					RequestSender(common::sockets::TcpSocket* tcpSocket);
					virtual ~RequestSender();			
					/**
					 * {@inheritDocs}
					 */
					virtual void stop();	
			};
		}
	}
}

#endif /*CLIENT_GAME_MODEL_REQUESTSENDER_H_*/
