#ifndef COMMON_THREADS_LOCKS_EXCLUSIVEWRITELOCK_H_
#define COMMON_THREADS_LOCKS_EXCLUSIVEWRITELOCK_H_

#include "readwritelock.h"

namespace common {
	namespace threads {
		namespace locks {

			/**
			 * Lock de Escritura Exclusivo.
			 * @author Gabriel Raineri
			 */
			class ExclusiveWriteLock {
				private:
					ReadWriteLock& rwLock;
					// No copiable.
					ExclusiveWriteLock(const ExclusiveWriteLock &ewl);
					// No asignable.
					ExclusiveWriteLock& operator=(const ExclusiveWriteLock &ewl);  
			  
				public:
					/**
					 * Constructor. 
					 * Efectua un lock exclusivo de escritura sobre el ReadWriteLock 
					 * pasado como parametro. 
					 * @param rwLock El ReadWriteLock sobre el cual se efectuara el lock.
					 */
					ExclusiveWriteLock(ReadWriteLock& rwLock);
					/**
					 * Destructor. 
					 * Efectua un unlock del ReadWriteLock recibido en el constructor.  
					 */
					~ExclusiveWriteLock();
			};
		}
	}
}
#endif /*COMMON_THREADS_LOCKS_EXCLUSIVEWRITELOCK_H_*/
