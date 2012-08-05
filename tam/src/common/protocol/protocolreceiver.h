#ifndef COMMON_PROTOCOL_PROTOCOLRECEIVER_H_
#define COMMON_PROTOCOL_PROTOCOLRECEIVER_H_

#include <string>
#include "../sockets/tcpsocket.h"
#include "../sockets/data.h"

namespace common {
	namespace protocol {

		/**
		 * Se encarga de recibir datos utilizando el protocolo entre el cliente 
		 * y el servidor.
		 * @author Gabriel Raineri
		 */
		class ProtocolReceiver {
			public:
				/**
				 * Constructor.
				 */
				ProtocolReceiver();
				/**
				 * Destructor.
				 */
				virtual ~ProtocolReceiver();
				/**
				 * Recibe Datos de un Socket utilizando el protocolo.
				 * @param tcpSocket El Socket del cual se recibiran los datos.
				 * @return Los Datos recibidos del Socket.
				 */
				const common::sockets::Data* receiveFromSocket(
						const common::sockets::TcpSocket& tcpSocket) const;
				/**
				 * Recibe una cadena de un Socket utilizando el protocolo.
				 * @param tcpSocket El Socket del cual se recibiran los datos.
				 * @return La cadena recibida del Socket.
				 */
				const std::string receiveStrFromSocket(
						const common::sockets::TcpSocket& tcpSocket) const;		
		};
	}
}
#endif /*COMMON_PROTOCOL_PROTOCOLRECEIVER_H_*/
