#ifndef COMMON_UTILS_MATH_H_
#define COMMON_UTILS_MATH_H_

namespace common {
	namespace utils {

		/**
		 * Clase Utilitaria con funciones matematicas.
		 */
		class Math {
			private:
				// No instanciable.
				Math();
				~Math();
				// No copiable.
				Math(const Math &m);
				// No asignable.
				Math& operator=(const Math &m);

			public:
				/**
				 * Cuenta la cantidad de digitos que contiene el numero.
				 * @param number El numero.
				 * @return El numero de digitos.
				 */
				static char countDigits(int number);

				static const double PI;
		};
	}
}
#endif /*COMMON_UTILS_MATH_H_*/
