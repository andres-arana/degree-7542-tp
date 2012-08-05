#ifndef COMMON_THREADS_THREAD_H_
#define COMMON_THREADS_THREAD_H_

#include <pthread.h>
#include "locks/readwritelock.h"

namespace common {	
	namespace threads {		
		
		/**
		 * Representacion de un Hilo.
		 * @author Gabriel Raineri
		 */
		class Thread {
			private:
				// No copiable.
				Thread(const Thread &t);
				// No asignable.
				Thread& operator=(const Thread &t);    
				common::threads::locks::ReadWriteLock* rwLock;
				pthread_t tid;
				bool stopped;
				// Metodo a ser invocado desde el pthread_create.
				static void* static_run(void* argThis);
		  
			protected:
				/**
				 * Metodo que sera invocado cuando se inicie el hilo.
				 */
		    virtual void run() = 0;
		  
		  public:
				/**
				 * Constructor.
				 */
		    Thread();
		    /**
		     * Destructor.
		     */
		    virtual ~Thread();    
				/**
				 * Crea e inicia el hilo.
				 */
		    virtual void start();
				/**
				 * Modifica el estado del hilo a stopped. No cancela la ejecucion del mismo.
				 */
		    virtual void stop();
				/**
				 * Cancela el hilo.
				 */
		    virtual void cancel();
				/**
				 * Retorna si el hilo fue detenido.
				 * @return Verdadero si el hilo esta detenido. Falso, sino.
				 */
		    bool isStopped() const;
				/**
				 * Retorna el ID del hilo.
				 * @return El ID del hilo.
				 */
		    pthread_t getTid() const;
				/**
				 * Retorna el lock de lectura/escritura perteneciente al hilo.
				 * @return El lock de lectura/escritura.
				 */
		    common::threads::locks::ReadWriteLock& getLock() const;
		    /**
		     * Detiene el hilo que lo invoca hasta la finalizacion del hilo actual.
		     */
		    virtual void join();    
				/**
				 * Detiene el hilo que lo invoca hasta la finalizacion del hilo 
				 * que se recibe como parametro.
				 * @param pthread_t El ID del hilo a ser detenido. 
				 */
				static void join(pthread_t threadId);
				/**
				 * Retorna el ID del hilo que lo invoca.
				 * @return El ID del hilo que invoca el metodo.
				 */
				static pthread_t getCurrentThread(); 
				/**
				 * Duerme al hilo invocante por (al menos) los milisegundos recibidos 
				 * como parametro.
				 * @param ms Los milisegundos que debe dormir el hilo invocante. 
				 */
				static void sleep(int ms);      
		};
	}
}
#endif /*COMMON_THREADS_THREAD_H_*/
