#ifndef CLIENT_GAME_COMMANDS_COMMANDFACADE_H_
#define CLIENT_GAME_COMMANDS_COMMANDFACADE_H_

#include <string>

namespace client {
	namespace game {
		namespace facade {
			/**
			 * Facade para la ejecucion de Comandos.
			 * @author Gabriel Raineri 
			 */
			class CommandFacade {
				private:
					CommandFacade();
					~CommandFacade();
					// No copiable.
			    CommandFacade(const CommandFacade &cf);
			    // No asignable.
			    CommandFacade& operator=(const CommandFacade &cf);
					
					static void addRequest(
							const std::string& cmdName, const std::string& params = ""); 
					
				public:
					/**
					 * Ejecuta una solicitud login en el server utilizando el nombre 
					 * indicado como parametro.
					 * @param loginName El nombre utilizado para loguearse.
					 */
					static void login(const std::string& loginName);
					/**
					 * Ejecuta una solicitud de sesiones disponibles al servidor.
					 */
					static void getAvailableSessions();
					/**
					 * Ejecuta una solicitud de union a la sesion indicada como 
					 * parametro.
					 * @param sessionId El Id de sesion al cual quiere unirse.
					 */
					static void joinSession(const std::string& sessionId);
					/**
					 * Ejecuta una solicitud de creacion de Sesion Monousuario.
					 */
					static void createSinglePlayerSession();
					/**
					 * Ejecuta una solicitud de creacion de Sesion Multiusuario.
					 */
					static void createMultiPlayerSession();
					/**
					 * Ejecuta una solicitud del siguiente nivel disponible.
					 */
					static void getNextLevel();
					/**
					 * Envia un mensaje de chat.
					 * @param message El mensaje a ser enviado.
					 */
					static void sendChatMessage(const std::string& message);
					/**
					 * Ejecuta una solicitud al servidor para marcar el nivel actual como 
					 * completado enviando el puntaje obtenido en el mismo.
					 * @param score El puntaje obtenido en el nivel.
					 */
					static void markLevelAsCompleted(const std::string& score);
					/**
					 * Ejecuta una solicitud al servidor para marcar el nivel actual como
					 * NO completado.
					 */					 
					static void markLevelAsFailed();
					/**
					 * Envia el feedback (disposicion de los elementos en pantalla) al 
					 * servidor.
					 * @param feedbackStr Cadena de caracteres conteniendo el feedback.
					 */
					static void sendFeedback(const std::string& feedbackStr);
			};
		}
	}
}

#endif /*CLIENT_GAME_COMMANDS_COMMANDFACADE_H_*/
