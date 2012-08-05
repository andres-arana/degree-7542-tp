#ifndef __GAME__CORE__TIMEDELTA_H_INCLUDED__
#define __GAME__CORE__TIMEDELTA_H_INCLUDED__

#include <sys/time.h>

namespace game {
	namespace core {
		/**
		 * Clase de ayuda que permite obtener y calcular intervalos temporales
		 * con alta precision. La implementacion de esta clase se adapta
		 * al entorno (*nix, windows) en el que se esta compilando, y por lo
		 * tanto la precision de la medicion depende del entorno de compilacion.
		 * La clase almacena un milestone temporal, y permite calcular diferencias
		 * de tiempos con ese milestone almacenado.
		 */
		class TimeDelta {
		public:
			/**
			 * Crea una nueva instancia de TimeDelta, inicializando el milestone
			 * al tiempo actual.
			 */
			inline TimeDelta() {
				gettimeofday(&last_timeval, 0);
			}

			/**
			 * Obtiene la diferencia, en segundos, entre el ultimo milestone temporal
			 * y el instante de tiempo actual.
			 * @return Diferencia en segundos desde el ultimo milestone terminal al
			 * tiempo actual.
			 */
			inline double getDeltaFromTimeMilestone() const {
				timeval current_timeval;
				gettimeofday(&current_timeval, 0);

				double delta_seconds = current_timeval.tv_sec - last_timeval.tv_sec;
				double delta_microseconds = current_timeval.tv_usec - last_timeval.tv_usec;

				return delta_seconds + (delta_microseconds / 1000000);
			}

			/**
			 * Actualiza el milestone temporal al instante de tiempo actual.
			 */
			inline void updateTimeMilestone() {
				gettimeofday(&last_timeval, 0);
			}

		private:
			timeval last_timeval;
		};
	}
}

#endif
