#ifndef SERVER_GAME_LEVELS_EXCEPTIONS_NOMORELEVELSEXCEPTION_H_
#define SERVER_GAME_LEVELS_EXCEPTIONS_NOMORELEVELSEXCEPTION_H_

#include <exception>
#include <string>

namespace server {
	namespace game {
		namespace levels {
			namespace exceptions {
				
				/**
				 * Excepcion que indica que no existen mas niveles.
				 * @author Gabriel Raineri
				 */				 
				class NoMoreLevelsException : public std::exception {
				  private:
				    const std::string details;
				    
				  public:
				    NoMoreLevelsException(const std::string& details);
				    virtual ~NoMoreLevelsException() throw();
				    virtual const char* what() const throw();
				};				
			}
		}
	}
}

#endif /*SERVER_GAME_LEVELS_EXCEPTIONS_NOMORELEVELSEXCEPTION_H_*/
