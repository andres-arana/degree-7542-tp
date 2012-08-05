#ifndef COMMON_SOCKETS_EXCEPTIONS_TCPSOCKETEXCEPTION_H_
#define COMMON_SOCKETS_EXCEPTIONS_TCPSOCKETEXCEPTION_H_

#include <exception>
#include <string>

namespace common {
	namespace sockets {
		namespace exceptions {
			
			static const std::string ERR_PREFIX = "Error en Socket - ";			
			/**
			 * Clase de Excepcion para el manejo de errores con Sockets.
			 * @author Gabriel Raineri
			 */
			class TcpSocketException : public std::exception {
				private:
					const std::string details;
			    
				public:
					/**
					 * Constructor.
					 * @param details Los detalles del error ocurrido.
					 */
					TcpSocketException(const std::string& details);
					/**
					 * Destructor.
					 */
					virtual ~TcpSocketException() throw();
					/**
					 * Retorna el mensaje de error.
					 * @return El mensaje de error.
					 */
					virtual const char* what() const throw();
			};
		}
	}
}
#endif /*TCPSOCKETEXCEPTION_H_*/
