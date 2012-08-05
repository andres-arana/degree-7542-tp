#ifndef COMMON_THREADS_LOCKS_CONDITIONALWAIT_H_
#define COMMON_THREADS_LOCKS_CONDITIONALWAIT_H_

#include <pthread.h>
#include "mutex.h"

namespace common {
	namespace threads {
		namespace locks {
			/**
			 * Manejo de Variables de Condicion.
			 * @author Gabriel Raineri
			 */
			class ConditionalWait {
				private:
					// No copiable.
					ConditionalWait(const ConditionalWait &cw);
					// No asignable.
					ConditionalWait& operator=(const ConditionalWait &cw);
					Mutex mutex;
					pthread_cond_t* cond;
					int counter;
					
				public:
					ConditionalWait();
					~ConditionalWait();
					
					/**
					 * Espera hasta que se dispare un signal o broadcast.
					 */
					void wait();
					/**
					 * Despierta a todos los threads que estan detenidos esperando la 
					 * condicion.
					 */
					void broadcast();
					/**
					 * Despierta al menos un thread que este detenido esperando la 
					 * condicion.
					 */
					void signal();
			};
		}
	}
}

#endif /*COMMON_THREADS_LOCKS_CONDITIONALWAIT_H_*/
