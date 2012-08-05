#ifndef CLIENT_GAME_MODEL_MESSAGE_H_
#define CLIENT_GAME_MODEL_MESSAGE_H_

#include <string>

namespace client {
	namespace game {
		namespace model {
			/**
			 * Wrapper para los mensajes de un jugador.
			 * @author Gabriel Raineri
			 */		
			class Message {
			  private: 
			    std::string from;
			    std::string text;
			    
			  public:
			    /**
			     * Constructor. 
			     * Recibe el remitente y el texto del mensaje.
			     */
			    Message(const std::string& from, const std::string& text);
			    /**
			     * Retorna el remitente del mensaje.
			     */
			    const std::string& getFrom() const;
			    /**
			     * Retorna el texto del mensaje.
			     */
			    const std::string& getText() const;    
			    /**
			     * Construye un mensaje, analizando la cadena recibida en base al 
			     * protocolo de comunicacion entre el cliente y el servidor.
			     */
			    static const Message* createMessage(const std::string& messageStr);
			};
		}	
	}
}
#endif /*CLIENT_GAME_MODEL_MESSAGE_H_*/
