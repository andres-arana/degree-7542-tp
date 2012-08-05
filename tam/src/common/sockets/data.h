#ifndef COMMON_SOCKETS_DATA_H_
#define COMMON_SOCKETS_DATA_H_

#include <string>

namespace common {
	namespace sockets {
		/**
		 * Representacion de Datos recibidos de un Socket.
		 * @author Gabriel Raineri 
		 */
		class Data {
			private:
				// No copiable
				Data(const Data& d);
				// No asignable
				Data& operator=(const Data& d);
				const char* data;
				int length;
		    
			public:
				/**
				 * Constructor.
				 * Recibe los datos y la longitud de los mismos.
				 * Se efectua una copia de los datos segun el parametro 
				 * copyData lo indique.
				 * @param data Los datos.
				 * @param length La longitud de los datos.
				 * @param copyData Indica si deben copiarse o no los datos.
				 */
				Data(const char* data, int length, bool copyData = true);
				/**
				 * Constructor.
				 * Recibe una cadena de caracteres.
				 * Se efectua una copia de ellos.
				 * @param str La cadena de caracteres.
				 */
				Data(const std::string& str);
				/**
				 * Destructor.
				 * Libera el puntero a char contenido.
				 */
				~Data();
				/**
				 * Retorna el puntero a char contenido.
				 * @return El puntero a char contenido.
				 */
				const char* getData() const;
				/**
				 * Retorna la longitud de los datos contenidos.
				 * @return La longitud de los datos contenidos.
				 */
				int getLength() const;
		};
	}
}
#endif /*COMMON_SOCKETS_DATA_H_*/
