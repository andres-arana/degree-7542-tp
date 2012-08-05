#ifndef CLIENT_GAME_MODEL_OUTCOMINGREQUESTQUEUE_H_
#define CLIENT_GAME_MODEL_OUTCOMINGREQUESTQUEUE_H_

#include <vector>
#include <string>
#include "threads/locks/mutex.h"
#include "threads/locks/conditionalwait.h"
#include "message.h"

namespace client {
	namespace game {
		namespace commands {
			class Command;
		}
		namespace model {			
			/**
			 * Cola de Requests a enviar al Game Server.
			 * @author Gabriel Raineri
			 */
			class OutcomingRequestQueue {
			  private:         
			    OutcomingRequestQueue();
			    ~OutcomingRequestQueue();
			    // No copiable.
			    OutcomingRequestQueue(const OutcomingRequestQueue &rq);
			    // No asignable.
			    OutcomingRequestQueue& operator=(const OutcomingRequestQueue &rq);
			    /** 
			     * Como esta clase es un Singleton y es accedida por varios threads, 
			     * necesito sincronizar el acceso a recursos. 
			     */
			    common::threads::locks::Mutex mutex;
			    /**
			     * Vector que contiene los requests.
			     */
			    std::vector<const commands::Command*> requests;
			    /**
			     * Variable Condicional.
			     */
			    common::threads::locks::ConditionalWait conditionalWait; 
			    
				public:
					/**
					 * Retorna la unica instancia de la clase.
					 */
					static OutcomingRequestQueue& getInstance();					
					/**
					 * Agrega un request a la cola de requests.
					 * @param request El request a ser agregado.
					 */
					void addRequest(const commands::Command* request);			    
					/**
					 * Retorna todos los requests encolados y los elimina de la cola.
					 * @return Los requests encolados.
					 */
					std::vector<const commands::Command*>* getAllQueuedRequests();
					/**
					 * Retorna el objeto de Espera Condicional.
					 * @return El objeto de Espera Condicional.
					 */
					common::threads::locks::ConditionalWait* getConditionalWait();
					/**
					 * Libera la Espera Condicional.
					 */
					void releaseConditionalWait();
			};	
		}
	}
}

#endif /*CLIENT_GAME_MODEL_OUTCOMINGREQUESTQUEUE_H_*/
