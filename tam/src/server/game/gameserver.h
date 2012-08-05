#ifndef SERVER_GAME_GAMESERVER_H_
#define SERVER_GAME_GAMESERVER_H_

#include <string>
#include <list>
#include "../server.h"
#include "sessions/gamesession.h"

namespace server {
	namespace game {
		/**
		 * Servidor del Juego.
		 * 
		 * @author Gabriel Raineri
		 */
		class GameServer : public server::Server {				
			protected:
				virtual void run();
				
			public:
				/**
				 * Puerto por defecto.
				 */
				static unsigned short DEFAULT_PORT;				
				/**
		     * Inicia la ejecucion del Game Server en la IP y puerto parametrizados.
		     * @param ip La IP donde se iniciara el Server.
		     * @param port El puerto donde se iniciara el Server.
		     * @throws SocketException en caso de error con el socket.
		     */    
		    virtual void startServer(const std::string& ip, 
		    		unsigned short port = GameServer::DEFAULT_PORT);
				/**
		     * Inicia la ejecucion del Game Server en la IP local y el puerto 
		     * parametrizado.
		     * @param port El puerto donde se iniciara el Server.
		     * @throws SocketException en caso de error con el socket.
		     */    
		    virtual void startServer(unsigned short port = GameServer::DEFAULT_PORT);
				/**
				 * Detiene el funcionamiento del Game Server y libera los recursos 
				 * asociados.
				 */
				virtual void shutdownServer();
		};
	}
}
#endif /*SERVER_GAME_GAMESERVER_H_*/
