#ifndef COMMON_SOCKETS_TCPSOCKET_H_
#define COMMON_SOCKETS_TCPSOCKET_H_

#include <arpa/inet.h>
#include <netdb.h>
#include <string>
#include "data.h"

namespace common {
	namespace sockets {

		typedef struct sockaddr SocketAddress;
		typedef struct sockaddr_in SocketAddressIn;
		typedef struct hostent HostInfo;
		typedef struct in_addr Address;
		/**
		 * Representacion de un Socket TCP.
		 * @author Gabriel Raineri
		 * @author Andres Arana
		 */
		class TcpSocket {
			private:
				// No copiable.
				TcpSocket(const TcpSocket &t);
				// No asignable.
				TcpSocket& operator=(const TcpSocket &t);
				
				static const int DEFAULT_BACKLOG;    
				/**
				 * El Socket File Descriptor.
				 */
				int socketFD;
				/**
				 * Constructor.
				 * Permite crear un TcpSocket con un Socket File Descriptor.
				 * @param socketFD El File Descriptor.
				 */
				TcpSocket(int socketFD);
				/**
				 * Asigna un Socket Address con la IP y puerto especificado.
				 * @param ip La IP en formato unsigned long.
				 * @param port El puerto
				 */
				void assignSocketAddressIn(unsigned long ip, unsigned short port, 
						SocketAddressIn* socketAddress) const;
				/**
				 * Asigna un Socket Address con la IP y puerto especificado.
				 * @param address La estructura con la info a la que conectarse.
				 * @param port El puerto.
				 */
				void assignSocketAddressIn(Address& address, unsigned short port, 
						SocketAddressIn* socketAddress) const;
				
				void initSocketAddressIn(unsigned short port, 
						SocketAddressIn* socketAddress) const;
			public:
				/**
				 * Constructor.
				 * Inicializa el Socket obteniendo un File Descriptor para el mismo.
				 * @throws TcpSocketException En caso de que ocurra algun error con el 
		     * 		Socket.
				 */
				TcpSocket();		
				/**
				 * Destructor.
				 */
				virtual ~TcpSocket();
				/**
				 * Tipos de Shutdown.
				 */       
				enum ShutdownType {
		      DISABLE_RECEPTION = 0,
		      DISABLE_SENDING = 1,
		      DISABLE_ALL = 2
		    };
				/** 
				 * Asigna el socket para que funcione sobre la IP y puerto 
				 * parametrizados.
				 * @param ipAddress La IP a la que se asignara el socket.
				 * @param port El puerto al que se asignara el socket.
				 * @throws TcpSocketException En caso de que ocurra algun error con el 
		     * 		Socket.
				 */
				void bindSocket(const std::string& ip, unsigned short port) const;
				/** 
				 * Asigna el socket para que funcione sobre la IP local y el puerto 
				 * parametrizado.
				 * @param port El puerto al que se asignara el socket.
				 * @throws TcpSocketException En caso de que ocurra algun error con el 
		     * 		Socket.
				 */
				void bindSocket(unsigned short port) const;
				/**
				 * Inicializa la cola de espera recibiendo su tamanio maximo.
				 * @param backlog El tamanio maximo de la cola de espera.
				 * @throws TcpSocketException En caso de que ocurra algun error con el 
		     * 		Socket.
				 */
				void listenSocket(int backlog = DEFAULT_BACKLOG) const; 
				/**
		     * Conexion a un Host utilizando la ip y puerto parametrizados.
		     * @param ipAddress La IP a la que se conectara.
				 * @param port El puerto al que se conectara.
		     * @throws TcpSocketException En caso de que ocurra algun error con el 
		     * 		Socket.
		     */
		    void connectToHost(const std::string& ip, unsigned short port) const; 
		    /**
				 * Acepta una petición de conexión, devolviendo un socket para 
				 * comunicarse a través de la conexión aceptada.
				 * @throws TcpSocketException En caso de que ocurra algun error con el 
				 * 		Socket.
				 * @return Un puntero a TcpSocket para permitir la comunicacion.
				 */
		    TcpSocket* acceptConnection() const;
				/** 
				 * Enviar un stream de datos.
				 * @param data Los datos a enviar.
				 * @throws TcpSocketException En caso de que ocurra algun error con el 
				 * 		Socket.
				 */ 
				void sendData(const Data& data) const;    
				/**
				 * Recibir un stream de datos de longitud parametrizada.
				 * @param length La longitud que se desea recibir.
				 * @return Los datos recibidos.
				 * @throws TcpSocketConnectionClosedException En caso de que el socket 
				 * 		remoto haya cerrado la conexion.
				 * @throws TcpSocketException En caso de que ocurra algun error con el 
				 * 		Socket. 
				 */
				const Data* receiveData(int length) const;
				/**
				 * Desconecta el Socket utilizando el tipo dado.
				 * @param type El tipo de Shutdown.
				 * @throws TcpSocketException En caso de que ocurra algun error con el 
				 * 		Socket. 
				 */
				void shutdownSocket(ShutdownType type) const;     
				/**
				 * Cierra el Socket.
				 * @throws TcpSocketException En caso de que ocurra algun error con el 
				 * 		Socket. 
				 */
				void closeSocket() const;    
		};
	}
}
#endif /*COMMON_SOCKETS_TCPSOCKET_H_*/
