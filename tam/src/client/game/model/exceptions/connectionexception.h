#ifndef CLIENT_GAME_MODEL_EXCEPTIONS_CONNECTIONEXCEPTION_H_
#define CLIENT_GAME_MODEL_EXCEPTIONS_CONNECTIONEXCEPTION_H_

#include <exception>
#include <string>

namespace client {
	namespace game {
		namespace model {			
			namespace exceptions {
							
				/**
				 * Clase de Excepcion para el manejo de errores en la conexion con el 
				 * Servidor.
				 * @author Gabriel Raineri
				 */
				class ConnectionException : public std::exception {				    
					public:
						/**
						 * Retorna el mensaje de error.
						 * @return El mensaje de error.
						 */
						virtual const char* what() const throw() {
							return "Error en la conexion con el Servidor.";
						}
				};
			}
		}
	}	
}

#endif /*CLIENT_GAME_MODEL_EXCEPTIONS_CONNECTIONEXCEPTION_H_*/
