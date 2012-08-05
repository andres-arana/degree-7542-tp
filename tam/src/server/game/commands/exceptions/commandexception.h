#ifndef SERVER_GAME_COMMANDS_EXCEPTIONS_COMMANDEXCEPTION_H_
#define SERVER_GAME_COMMANDS_EXCEPTIONS_COMMANDEXCEPTION_H_

#include <exception>
#include <string>

namespace server {
	namespace game {
		namespace commands {
			namespace exceptions {
	
				class CommandException : public std::exception {
				  private:
				    const std::string details;
				    
				  public:
				    CommandException(const std::string& details);
				    virtual ~CommandException() throw();
				    virtual const char* what() const throw();
				};
			}
		}
	}
}
#endif /*SERVER_GAME_COMMANDS_EXCEPTIONS_COMMANDEXCEPTION_H_*/
