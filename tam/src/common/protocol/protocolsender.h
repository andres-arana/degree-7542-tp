#ifndef COMMON_PROTOCOL_PROTOCOLSENDER_H_
#define COMMON_PROTOCOL_PROTOCOLSENDER_H_

#include <string>
#include "../sockets/tcpsocket.h"
#include "../sockets/data.h"

namespace common {	
	namespace protocol {

		/**
		 * Se encarga de realizar envios utilizando el protocolo entre el cliente 
		 * y el servidor.
		 * @author Gabriel Raineri
		 */
		class ProtocolSender {
			private:
				/**
				 * Empaqueta y envia los datos contenidos en la cadena siguiendo el 
				 * protocolo.
				 * @param str La cadena a ser empaquetada y enviada.
				 */
				void sendPackage(const common::sockets::TcpSocket& tcpSocket, 
						const std::string& str) const;
				/**
				 * Empaqueta y envia los datos contenidos en data siguiendo el protocolo.
				 * @param data Los datos a ser empaquetados y enviados.
				 */		
				void sendPackage(const common::sockets::TcpSocket& tcpSocket, 
						const common::sockets::Data& data) const;
				
			public:
				/**
				 * Constructor.
				 */
				ProtocolSender();
				/**
				 * Destructor.
				 */
				virtual ~ProtocolSender();
				/**
				 * Envia una cadena a un Socket utilizando el protocolo.
				 * @param tcpSocket El Socket al cual se le enviara el mensaje.
				 * @param message El mensaje a ser enviado.
				 */
				void sendToSocket(const common::sockets::TcpSocket& tcpSocket, 
						const std::string& message)	const; 
				/**
				 * Envia Datos a un Socket utilizando el protocolo.
				 * @param tcpSocket El Socket al cual se le enviara el mensaje.
				 * @param data Los datos a ser enviados.
				 */
				void sendToSocket(const common::sockets::TcpSocket& tcpSocket, 
						const common::sockets::Data& data) const; 	
		};
	}
}
#endif /*COMMON_PROTOCOL_PROTOCOLSENDER_H_*/
