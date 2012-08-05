#ifndef CLIENT_GAME_COMMANDS_LEVELCOMMAND_H_
#define CLIENT_GAME_COMMANDS_LEVELCOMMAND_H_

#include "command.h"
#include "protocol/protocolreceiver.h"
#include "sockets/tcpsocket.h"
#include <fstream>

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Comando para solicitar niveles al servidor.
			 * @author Gabriel Raineri
			 */
			class LevelCommand : public Command {
				private:
					common::protocol::ProtocolReceiver protocolReceiver;
					
					void receiveFile(common::sockets::TcpSocket* tcpSocket, 
							long fileSize, const std::string& destination, 
							std::ios_base::openmode mode = std::ios_base::out);
					long getSizeFromHeader(common::sockets::TcpSocket* tcpSocket);
					void receiveImage(common::sockets::TcpSocket* tcpSocket);
					void receiveXml(common::sockets::TcpSocket* tcpSocket);
					void receiveLevel(client::game::model::GameClient* gameClient);
					
				public:
					virtual std::string buildRequest() const;
			    		
			    virtual void executeResponse(
			    		client::game::model::GameClient* gameClient);
			};			 
		}
	}
}

#endif /*CLIENT_GAME_COMMANDS_LEVELCOMMAND_H_*/
