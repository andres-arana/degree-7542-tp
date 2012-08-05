#ifndef COMMON_THREADS_LOCKS_READWRITELOCK_H_
#define COMMON_THREADS_LOCKS_READWRITELOCK_H_

#include <pthread.h>

namespace common {
	namespace threads {
		namespace locks {
			/**
			 * Lock de Lectura/Escritura.
			 * @author Gabriel Raineri
			 */
			class ReadWriteLock {
				private:
					pthread_rwlock_t lock;
					// No copiable.
					ReadWriteLock(const ReadWriteLock &rwl);
					// No asignable.
					ReadWriteLock& operator=(const ReadWriteLock &rwl);
			    
				public:
					/**
					 * Constructor.
					 */
					ReadWriteLock();
					/**
					 * Destructor.
					 */
					~ReadWriteLock();    
					/**
					 * Adquiere un Lock Compartido de Lectura.
					 */
					void sharedReadLock();
					/**
					 * Adquiere un Lock Exclusivo de Escritura.
					 */
					void exclusiveWriteLock();
					/**
					 * Libera el Lock.
					 */
					void unlock();
			};
		}
	}
}
#endif /*COMMON_THREADS_LOCKS_READWRITELOCK_H_*/
