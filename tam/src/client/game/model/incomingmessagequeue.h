#ifndef CLIENT_GAME_MODEL_INCOMINGMESSAGEQUEUE_H_
#define CLIENT_GAME_MODEL_INCOMINGMESSAGEQUEUE_H_

#include <vector>
#include <string>
#include "threads/locks/mutex.h"
#include "message.h"

namespace client {
	namespace game {
		namespace model {
			/**
			 * Cola de Mensajes recibidos.
			 * @author Gabriel Raineri
			 */
			class IncomingMessageQueue {
			  private:         
			    IncomingMessageQueue();
			    ~IncomingMessageQueue();
			    // No copiable.
			    IncomingMessageQueue(const IncomingMessageQueue &mq);
			    // No asignable.
			    IncomingMessageQueue& operator=(const IncomingMessageQueue &mq);
			    /** 
			     * Como esta clase es un Singleton y es accedida por varios threads, 
			     * necesito sincronizar el acceso a recursos. 
			     */
			    common::threads::locks::Mutex mutex;
			    /**
			     * Vector que contiene los mensajes.
			     */
			    std::vector<const Message*> messages; 
			    
				public:
					/**
					 * Retorna la unica instancia de la clase.
					 */
					static IncomingMessageQueue& getInstance();
					
					/**
					 * Agrega un mensaje a la cola de mensajes.
					 * @param message El mensaje a ser agregado.
					 */
					void addMessageToQueue(const Message* message);
			    
					/**
					 * Retorna todos los mensajes encolados y los elimina de la cola.
					 * @return Los mensajes encolados.
					 */
					std::vector<const Message*>* getAllQueuedMessages();
			};	
		}
	}
}

#endif /*CLIENT_GAME_MODEL_INCOMINGMESSAGEQUEUE_H_*/
