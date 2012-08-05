#ifndef COMMON_THREADS_LOCKS_MUTEX_H_
#define COMMON_THREADS_LOCKS_MUTEX_H_

#include <pthread.h>

namespace common {
	namespace threads {
		namespace locks {
			/**
			 * Exclusion Mutua.
			 * @author Gabriel Raineri
			 */
			class Mutex {
				private:
					pthread_mutex_t mutex;   
					// No copiable.
					Mutex(const Mutex &m);
					// No asignable.
					Mutex& operator=(const Mutex &m);
			    
				public:
					/**
					 * Constructor.
					 */
					Mutex();
					/**
					 * Destructor.
					 */
					~Mutex();    
					/**
					 * Adquiere el Mutex.
					 */
			    void lock();    
					/**
					 * Libera el Mutex.
					 */
			    void unlock();
			    /**
			     * Devuelve la estructura del Mutex.
			     */
			    pthread_mutex_t* getMutex();
			};
		}
	}
}
#endif /*COMMON_THREADS_LOCKS_MUTEX_H_*/
