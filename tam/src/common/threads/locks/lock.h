#ifndef COMMON_THREADS_LOCKS_LOCK_H_
#define COMMON_THREADS_LOCKS_LOCK_H_

#include "mutex.h"

namespace common {
	namespace threads {
		namespace locks {

			/**
			 * Lock de Exclusion Mutua (Mutex).
			 * @author Gabriel Raineri
			 */ 
			class Lock {
				private:
					// No copiable.
					Lock(const Lock &l);
					// No asignable.
					Lock& operator=(const Lock &l);
			    
					Mutex& mutex;
			    
				public:
					/**
					 * Constructor. 
					 * Efectua un lock del mutex pasado como parametro.
					 * @param mutex El mutex sobre el que se efectua el lock.
					 */
			    Lock(Mutex& mutex);
					/** 
					 * Destructor.
					 * Efectua un unlock del mutex recibido en el constructor.
					 */
			    ~Lock();
			};
		}
	}
}
#endif /*LOCK_H_*/
