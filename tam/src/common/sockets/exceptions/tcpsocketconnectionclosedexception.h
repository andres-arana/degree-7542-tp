#ifndef COMMON_SOCKETS_EXCEPTIONS_TCPSOCKETCONNECTIONCLOSEDEXCEPTION_H_
#define COMMON_SOCKETS_EXCEPTIONS_TCPSOCKETCONNECTIONCLOSEDEXCEPTION_H_

#include "tcpsocketexception.h"

namespace common {
	namespace sockets {
		namespace exceptions {
			/**
			 * Clase de Excepcion que indica que la conexion con el Socket fue 
			 * cerrada.
			 * @author Gabriel Raineri
			 * @author Andres Arana
			 */
			class TcpSocketConnectionClosedException : public TcpSocketException {
				public:
					/**
					 * Constructor.
					 * @param details Los detalles del error ocurrido.
					 */				
					TcpSocketConnectionClosedException(const std::string& details);
					/**
					 * Destructor.
					 */
					virtual ~TcpSocketConnectionClosedException() throw();
			};
		}
	}
}

#endif /*COMMON_SOCKETS_EXCEPTIONS_TCPSOCKETCONNECTIONCLOSEDEXCEPTION_H_*/
