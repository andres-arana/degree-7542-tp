#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include <string>
#include "threads/thread.h"
#include "sockets/tcpsocket.h"

namespace server {
	/**
	 * Clase Abstracta para Servidores
	 * 
	 * @author Gabriel Raineri
	 */
	class Server : public common::threads::Thread {												
		protected:
			bool hasToShutdown;
			common::sockets::TcpSocket* acceptorSocket;
			virtual void initSocket(const std::string& ip, unsigned short port);
			virtual void run() = 0;
			
		public:
			/**
			 * Constructor.
			 */
			Server();
			/**
			 * Destructor.
			 */
			virtual ~Server();
			/**
	     * Inicia la ejecucion del Server en la IP y puerto parametrizados.
	     * @param ip La IP donde se iniciara el Server.
	     * @param port El puerto donde se iniciara el Server.
	     * @throws SocketException en caso de error con el socket.
	     */    
	    virtual void startServer(const std::string& ip, unsigned short port);
			/**
	     * Inicia la ejecucion del Server en la IP local y el puerto 
	     * parametrizado.
	     * @param port El puerto donde se iniciara el Server.
	     * @throws SocketException en caso de error con el socket.
	     */    
	    virtual void startServer(unsigned short port);
			/**
			 * Detiene el funcionamiento del Server y libera los recursos 
			 * asociados.
			 */
			virtual void shutdownServer();
	};
}

#endif /*SERVER_SERVER_H_*/
