#ifndef COMMON_THREADS_LOCKS_SHAREDREADLOCK_H_
#define COMMON_THREADS_LOCKS_SHAREDREADLOCK_H_

#include "readwritelock.h"

namespace common {
	namespace threads {
		namespace locks {
			/**
			 * Lock de Lectura Compartido.
			 * @author Gabriel Raineri
			 */
			class SharedReadLock {
				private:
					ReadWriteLock& rwLock;
					// No copiable.
					SharedReadLock(const SharedReadLock &srl);
					// No asignable.
					SharedReadLock& operator=(const SharedReadLock &srl);        
			  
				public:
					/** 
					 * Constructor. 
					 * Efectua un lock compartido de lectura sobre el ReadWriteLock pasado 
					 * como parametro.
					 * @param rwLock El ReadWriteLock sobre el cual se efectuara el lock.  
					 */
					SharedReadLock(ReadWriteLock& rwLock);
					/** 
					 * Destructor.
					 * Efectua un unlock del ReadWriteLock recibido en el constructor. 
					 */
					~SharedReadLock();
			};
		}
	}
}
#endif /*COMMON_THREADS_LOCKS_SHAREDREADLOCK_H_*/
