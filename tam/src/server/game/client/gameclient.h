#ifndef SERVER_GAME_CLIENT_GAMECLIENT_H_
#define SERVER_GAME_CLIENT_GAMECLIENT_H_

#include <string>
#include "sockets/data.h"
#include "sockets/tcpsocket.h"
#include "messagereceiver.h"
#include "messagesender.h"

namespace server {
	namespace game {
		namespace sessions {
			class GameSession;
		}
		namespace client {			
			/**
			 * Cliente de Juego.
			 * @author Gabriel Raineri
			 */
			class GameClient {
				private:
					std::string nick;
					server::game::sessions::GameSession* gameSession;
					common::sockets::TcpSocket* clientSocket;
					MessagePool* msgPool;
					MessageReceiver* msgReceiver;
					MessageSender* msgSender;
					int totalScore;
					
				public:
					/**
					 * Constructor.
					 */
					GameClient(common::sockets::TcpSocket* tcpSocket);
					/**
					 * Destructor.
					 */
					~GameClient();
					/**
					 * Inicializa el cliente para que comience a escuchar.
					 */ 
					void init();
					/**
					 * Establece el nick del cliente del Juego.
					 */
					void setNick(const std::string& nick);
					/**
					 * Retorna el nick del cliente del Juego.
					 * @return El nick del cliente del Juego.
					 */
					const std::string& getNick() const;
					/**
					 * Retorna el Socket del Cliente del Juego.
					 * @return El Socket del Cliente del Juego.
					 */
					common::sockets::TcpSocket* getSocket() const;
					/**
					 * Establece la Sesion del Juego en la que se encuentra el cliente.
					 */
					void setGameSession(server::game::sessions::GameSession* gameSession);
					/**
					 * Retorna la Sesion del Juego en la que se encuentra el Cliente.
					 * @return La Sesion del Juego en la que se encuentra el Cliente.
					 */
					server::game::sessions::GameSession* getGameSession() const;		
					/**
					 * Envia un mensaje al cliente.
					 * @param message El mensaje a ser enviado.
					 */
					void sendMessage(const std::string& message);
					/**
					 * Envia un mensaje al cliente.
					 * @param data El mensaje a ser enviado.
					 */
					void sendMessage(common::sockets::Data* data);
					/**
					 * Agrega un puntaje parcial al puntaje total.
					 * @param score El puntaje parcial a ser agregado.
					 */
					void addScore(int score);
					/**
					 * Devuelve el puntaje total del jugador.
					 * @return El puntaje total del jugador.
					 */
					int getTotalScore() const;
					/**
					 * Retorna si un cliente esta activo o no.
					 */
					bool isAlive() const;					
					/**
					 * Desconecta el cliente.
					 */
					void disconnect();
			};
		}
	}
}
#endif /*SERVER_GAME_CLIENT_GAMECLIENT_H_*/
