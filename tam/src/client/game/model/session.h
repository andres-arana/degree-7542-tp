#ifndef CLIENT_GAME_MODEL_SESSION_H_
#define CLIENT_GAME_MODEL_SESSION_H_

#include <string>

namespace client {
	namespace game {
		namespace model {
			/**
			 * Sesion
			 * @author Gabriel Raineri
			 */		
			class Session {
			  private: 
			    std::string id;
			    std::string name;
			    
			  public:
			    /**
			     * Constructor. 
			     * Recibe el id y el nombre de la sesion.
			     */
			    Session(const std::string& id, const std::string& name);
			    /**
			     * Retorna el id de la sesion.
			     */
			    const std::string& getId() const;
			    /**
			     * Retorna el nombre de la sesion.
			     */
			    const std::string& getName() const;    
			};
		}	
	}
}

#endif /*CLIENT_GAME_MODEL_SESSION_H_*/
