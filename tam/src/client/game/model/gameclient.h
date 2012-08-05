#ifndef CLIENT_GAME_MODEL_GAMECLIENT_H_
#define CLIENT_GAME_MODEL_GAMECLIENT_H_

#include <list>
#include "sockets/tcpsocket.h"
#include "protocol/protocolsender.h"
#include "threads/locks/mutex.h"
#include "serverlistener.h"
#include "requestsender.h"
#include "session.h"

namespace client {
	namespace game {
		namespace model {
			/**
			 * Cliente del Juego.
			 * @author Gabriel Raineri
			 */
			class GameClient {
				private:				
					common::protocol::ProtocolSender protocolSender;
					common::sockets::TcpSocket* tcpSocket;
					ServerListener* serverListener;
					RequestSender* requestSender;
					mutable common::threads::locks::Mutex mutex;
					bool responseReceived;
					bool loginSuccess;
					bool joinSuccess; 					
					std::list<Session*>* sessionList;
					bool opponentConnected;
					bool moreLevels;
					bool levelHasToStart;
					int totalScore;
					std::string feedbackStr;
					/**
					 * Inicializa el cliente para que comience a escuchar al servidor.
					 */
					void init();
					/**
					 * Limpia la lista de Sesiones.
					 */
					void clearSessionList();
					
				public:
					/**
					 * Constructor.
					 */
					GameClient();
					/**
					 * Destructor.
					 */
					virtual ~GameClient();
					/**
					 * Puerto por defecto.
					 */
					static unsigned short DEFAULT_PORT;
					/**
					 * Conecta el cliente a un Game Server utilizando la ip y puerto 
					 * especificados.
					 * @param ip La IP del Game Server.
					 * @param port Opcional. El puerto del Game Server.
					 * @throws ConnectionException en caso de error en la conexion.
					 */
					void connectToGameServer(
							const std::string& ip, unsigned short port = DEFAULT_PORT);
					/**
					 * Retorna el Socket utilizado para la conexion con el servidor.
					 * @return El Socket utilizado para la conexion con el servidor.
					 */
					common::sockets::TcpSocket* getSocket() const;
					/**
					 * Establece si se ha recibido una respuesta del servidor.
					 * @param received Si se ha recibido una respuesta del servidor.
					 */
					void setResponseReceived(bool received);
					/**
					 * Retorna si una respuesta del servidor ha sido recibida.
					 * @return Verdadero si ha llegado una respuesta del servidor. 
					 * 		Falso, si no.
					 */
					bool wasResponseReceived() const;
					/**
					 * Establece la lista de Sesiones disponibles.
					 */
					void setAvailableSessions(std::list<Session*>* sessionList);
					/**
					 * Retorna la lista de Sesiones disponibles.
					 */
					std::list<Session*>* getAvailableSessions() const;
					/**
					 * Establece si el login fue exitoso o no.
					 * @param success Verdadero si el login fue exitoso. Falso, si no lo fue.
					 */
					void setLoginSuccess(bool success);
					/**
					 * Retorna si el cliente esta logueado o no.
					 * @return Verdadero si el cliente esta logueado. Falso, si no.
					 */
					bool isLogged() const;
					/**
					 * Establece si el cliente pudo unirse a una sesion exitosamente.
					 * @param success Verdadero si la union fue exitosa. Falso si no lo fue.
					 */
					void setJoinSuccess(bool success);
					/**
					 * Retorna si la union fue exitosa o no.
					 * @return Verdadero si la union fue exitosa. Falso, si no.
					 */
					bool isJoined() const;
					/**
					 * Establece si el oponente esta conectado.
					 * @param connected Verdadero si el oponente esta conectado. Falso, si no.
					 */
					void setOpponentConnected(bool connected);
					/**
					 * Retorna si el oponente esta conectado.
					 * @return Verdadero si el oponentes esta conectado. Falso, si no.
					 */
					bool isOpponentConnected() const;
					/**
					 * Establece si el nivel debe comenzar.
					 * @param start Verdadero si el nivel debe comenzar. Falso, si no. 
					 */
					void setLevelStart(bool start);
					/**
					 * Retorna si el nivel debe comenzar.
					 * @return Verdadero si el nivel debe comenzar. Falso, si no.
					 */
					bool hasLevelToStart() const;
					/**
					 * Establece si hay mas niveles.
					 * @param moreLevels Si hay mas niveles.
					 */
					void setMoreLevels(bool moreLevels);
					/**
					 * Retorna si hay mas niveles.
					 * @return Si hay mas niveles.
					 */
					bool hasMoreLevels() const;
					/**
					 * Agrega un puntaje parcial al puntaje Total.
					 * @param score El puntaje total a ser agregado.
					 */
					void addScore(int score); 
					/**
					 * Devuelve el puntaje total.
					 * @return El puntaje total. 
					 */
					int getTotalScore() const;
					/**
					 * Retorna la cadena de caracteres conteniendo el feedback del 
					 * oponente.
					 * @return La cadena de caracteres conteniendo el feedback del 
					 * 		oponente.
					 */
					const std::string& getFeedbackStr() const;
					/**
					 * Establece la cadena de caracteres conteniendo el feedback del 
					 * oponente.
					 * @param feedbackStr La cadena de caracteres conteniendo el feedback 
					 * 		del oponente.
					 */
					void setFeedbackStr(const std::string& feedbackStr);
					/**
					 * Reestablece el estado del cliente.
					 */ 
					void resetStatus();
					/**
					 * Retorna si el cliente esta conectado al Game Server.
					 * @return Verdadero si el cliente esta conectado. 
					 * 		Falso, si no lo esta.
					 */
					bool isConnected() const;
					/**
					 * Desconecta al cliente del Game Server. 
					 * Libera los recursos asignados.
					 */
					void disconnect();
			};			
		}
	}
}

#endif /*CLIENT_GAME_MODEL_GAMECLIENT_H_*/
