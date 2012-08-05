#ifndef SERVER_GAME_SESSIONS_GAMESESSIONMANAGER_H_
#define SERVER_GAME_SESSIONS_GAMESESSIONMANAGER_H_

#include <list>
#include "gamesession.h"
#include "threads/locks/mutex.h"

namespace server {
	namespace game {
		namespace sessions {
			/**
			 * Clase encargada de manejar las sesiones de Juego.
			 * @author Gabriel Raineri
			 */
			class GameSessionManager {
				private:
					// No copiable.
					GameSessionManager(const GameSessionManager &gsm);
					// No asignable.
					GameSessionManager& operator=(const GameSessionManager &gsm);
					/**
					 * Constructor.
					 */
					GameSessionManager();
					/**
					 * Destructor.
					 */
					~GameSessionManager();
					/** 
					 * Como esta clase es un Singleton y es accedida por varios threads, 
					 * necesito sincronizar el acceso a recursos. 
					 */
					mutable common::threads::locks::Mutex mutex;
					
					static int SESSION_COUNTER;
					/** Lista de Sesiones de Juego */
					std::list<GameSession*> gameSessions;
					/** Lista de clientes esperando ingresar a una Sesion de Juego. */
					std::list<server::game::client::GameClient*> awaitingClients;
					/**
					 * Crea una sesion de juego.
					 * @isMultiplayer Indica si la sesion es multijugador o no.
					 * @return La sesion de Juego.
					 */
					GameSession* createGameSession(bool isMultiplayer);
					
					void removeIdleSessions();
					void removeIdleAwaitingClients();
					void clearIdleSessionsAndClients();
					
				public:
					/** 
					 * Retorna la unica instancia de la clase.
					 * @return La unica instancia de la clase.
					 */
	    		static GameSessionManager& getInstance();				
					/**
					 * Crea una nueva Sesion de Juego para un jugador y la retorna.
					 * @return La Sesion de Juego creada.
					 */
					GameSession* createSinglePlayerGameSession();
					/**
					 * Crea una nueva Sesion de Juego para mas de un jugador y la retorna.
					 * @return La Sesion de Juego creada.
					 */
					GameSession* createMultiPlayerGameSession();
					/**
					 * Retorna una Sesion de Juego dado su Id.
					 * @param gameSessionId El Id de la Sesion de Juego.
					 * @return La Sesion de Juego. NULL si no existe.
					 */
					GameSession* getGameSessionById(int gameSessionId);
					/**
					 * Retorna una lista con todas las Sesiones de Juego existentes.
					 * @return Todas las Sesiones de Juego existentes.
					 */
					const std::list<GameSession*>& getGameSessions();
					/**
					 * Agrega un Cliente a la lista de espera para ser asignado en una 
					 * sesion.
					 * @param gameClient El cliente de Juego.
					 */
					void addAwaitingClient(server::game::client::GameClient* gameClient);
					/**
					 * Agrega un cliente a una sesion de Juego dado el id de la sesion. 
					 * Elimina al cliente de la lista de espera.
					 * @param gameClient El cliente a ser agregado.
					 * @param gameSessionId El Id de la Sesion de Juego.
					 */
					void addClientToGameSession(
							server::game::client::GameClient* gameClient, 
							GameSession* gameSession);
					/**
					 * Determina si un nick esta siendo utilizado en alguna sesion.
					 * @return Verdadero si el nick esta en uso. Falso, si no.
					 */
					bool isNickInUse(const std::string& nick) const;
					/**
					 * Desconecta todas las sesiones de Juego.
					 */
					void disconnectAllGameSessions();				
			};
		}
	}
}

#endif /*SERVER_GAME_SESSIONS_GAMESESSIONMANAGER_H_*/
