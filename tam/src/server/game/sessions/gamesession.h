#ifndef SERVER_GAME_SESSIONS_GAMESESSION_H_
#define SERVER_GAME_SESSIONS_GAMESESSION_H_

#include <vector>
#include <string>
#include "sockets/tcpsocket.h"
#include "../client/gameclient.h"
#include "../levels/levelmanager.h"

namespace server {
	namespace game {
		namespace sessions {
			/**
			 * Sesion de Juego.
			 * @author Gabriel Raineri
			 */
			class GameSession {
				private:
					/** ID de la Sesion */
					int id;
					/** Mutex */
					mutable common::threads::locks::Mutex mutex;
					/** Lista de Clientes conectados a la sesion.*/
					std::vector<server::game::client::GameClient*> gameClients;
					/** Administrador de Niveles para la sesion. */
					server::game::levels::LevelManager levelManager;
					/** Indica si la sesion es multijugador o no. */
					bool multiplayer;
					/** Indica si la sesion esta llena o no. */
					bool full;
					/**
					 * Desconecta y remueve los clientes recibidos.
					 * @param vector<GameClient*> Los clientes a ser desconectados y 
					 * 		removidos de la sesion.
					 */
					void disconnectAndRemoveClients(
							const std::vector<server::game::client::GameClient*>& gameClients);
					
					/**
					 * Envia un mensaje al cliente asegurando que este se encuentre en
					 * condiciones de recibirlo y siempre que este sea diferente del que 
					 * se esta pasando como parametro.
					 */							
					void broadcastWithCondition(const std::string& message, 
							server::game::client::GameClient* gameClientToExclude) const;
					
				public:
					/**
					 * Constructor.
					 * @param sessionId El Id de la Sesion.
					 */
					GameSession(int sessionId, bool isMultiplayer);
					/**
					 * Destructor.
					 */
					~GameSession();
					/**
					 * Retorna el Id de la Sesion.
					 * @return El Id de la Sesion.
					 */
					int getSessionId() const;
					/**
					 * Retorna el administrador de niveles para la sesion.
					 * @return El administrador de niveles para la sesion.
					 */
					server::game::levels::LevelManager& getLevelManager();
					/**
					 * Agrega un cliente a la sesion.
					 * @param gameClient El Cliente a ser agregado a la sesion.
					 */
					void addClient(server::game::client::GameClient* gameClient);
					/**
					 * Retorna si la Sesion de Juego esta vacia.
					 * @return Verdadero si la Sesion esta vacia. Sino, falso.
					 */
					bool isEmpty() const;
					/**
					 * Retorna si la sesion es multijugador o no.
					 * @return Si la sesion es multijugador o no.
					 */
					bool isMultiplayer() const;
					/**
					 * Retorna si la sesion tiene la cantidad maxima de usuarios.
					 * @return Si la sesion tiene la cantidad maxima de usuarios.
					 */
					bool isFull() const;
					/**
					 * Retorna los clientes conectados a la sesion.
					 * @return Los clientes conectados a la sesion.
					 */
					const std::vector<server::game::client::GameClient*>& getGameClients() 
							const;
					/**
					 * Remueve aquellos clientes que no estan conectados.
					 * Retorna si la Sesion ha quedado vacia.
					 * @return Verdadero si la Sesion quedo vacia. Sino, falso.
					 */
					bool removeDisconnectedClients();
					/**
					 * Envia un Mensaje a los usuarios conectados en la sesion de Juego.
					 * @param message El mensaje a ser enviado.
					 */
					void broadcastMessage(const std::string& message) const;
					/**
					 * Envia un Mensaje a los usuarios conectados en la sesion de Juego,
					 * exceptuando el pasado como parametro.
					 * @param message El mensaje a ser enviado.
					 */
					void broadcastMessage(const std::string& message, 
							server::game::client::GameClient* gameClientToExclude) const;
					/**
					 * Determina si un nivel debe comenzar o no.
					 */
					bool hasLevelToStart();
					/**
					 * Determina si un nick esta siendo utilizado en alguna sesion.
					 * @return Verdadero si el nick esta en uso. Falso, si no.
					 */
					bool isNickInUse(const std::string& nick) const;
			};
		}
	}
}
#endif /*SERVER_GAME_SESSIONS_GAMESESSION_H_*/
