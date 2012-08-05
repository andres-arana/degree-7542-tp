#ifndef COMMON_UTILS_STRINGUTILS_H_
#define COMMON_UTILS_STRINGUTILS_H_

#include <string>
#include <sstream>

#define WHITESPACE ' '
#define EOS '\0'

namespace common {
	namespace utils {
		/**
		 * Clase Utilitaria para el manejo de cadenas.
		 * @author Gabriel Raineri
		 */
		class StringUtils {
			private:
				// No instanciable.
				StringUtils();
				~StringUtils();
				// No copiable.
				StringUtils(const StringUtils &su);
				// No asignable.
				StringUtils& operator=(const StringUtils &su);

			public:
				/**
				 * Convierte una cadena a un numero.
				 * El tipo del numero esta definido por T.
				 * @param str La cadena a ser convertida.
				 * @return El numero convertido.
				 */
		    template <typename T>
		    static T stringToNumber(const std::string& str) {
		      std::istringstream stringStream(str);
		      T n = 0;
		      stringStream >> n;
		      return n;
		    }
		    /**
		     * Convierte un numero en una cadena de caracteres.
		     * El tipo del numero esta definido por T.
		     * @param number El numero a ser convertido.
		     * @return La cadena de caracteres con el numero convertido.
		     */
		    template <typename T>
		    static std::string numberToString(T number) {
		    	std::stringstream stringStream;
		    	stringStream << number;
		    	return stringStream.str();
		    }

				/**
				 * Retorna si la cadena pasada como parametro es un numero.
				 * @param str La cadena a ser evaluada.
				 * @return Verdadero si la cadena es numerica. Falso, sino.
				 */
		    static bool isNumeric(const std::string& str) {
		    	std::istringstream stringStream(str);
		    	double n = 0;
		    	return stringStream >> n;
		    }

				/**
				 * Retorna una copia de cadena de caracteres recibida agregando el
				 * caracter de fin de cadena en caso de que se especifique.
				 * @param str La cadena a ser copiada.
				 * @param length Longitud de la cadena.
				 * @param appendEOS Especifica si debe agregarse o no el caracter de
				 * 			fin de linea a la cadena retornada.
				 * @return La copia de la cadena.
				 */
				static char* stringCopy(const char* str, int length, bool appendEOS);

				/**
				 * Retorna Verdadero si la cadena de caracteres recibida esta vacia o
				 * solo contiene caracteres en blanco. Falso sino.
				 * @param La cadena a ser chequeada.
				 */
				static bool isEmptyOrWhitespace(const std::string& str);
		};
	}
}
#endif /*COMMON_UTILS_STRINGUTILS_H_*/
