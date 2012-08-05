#ifndef CLIENT_GAME_COMMANDS_EXCEPTIONS_COMMANDEXCEPTION_H_
#define CLIENT_GAME_COMMANDS_EXCEPTIONS_COMMANDEXCEPTION_H_

#include <exception>
#include <string>

namespace client {
	namespace game {
		namespace commands {
			namespace exceptions {
	
				class CommandException : public std::exception {
				  private:
				    const std::string details;
				    
				  public:
				  	CommandException();
				    CommandException(const std::string& details);
				    virtual ~CommandException() throw();
				    virtual const char* what() const throw();
				};
			}
		}
	}
}
#endif /*CLIENT_GAME_COMMANDS_EXCEPTIONS_COMMANDEXCEPTION_H_*/
