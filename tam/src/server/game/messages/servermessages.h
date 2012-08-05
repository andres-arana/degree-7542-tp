#ifndef SERVER_GAME_MESSAGES_SERVERMESSAGES_H_
#define SERVER_GAME_MESSAGES_SERVERMESSAGES_H_

#include <string>

namespace server {
	namespace game {
		namespace messages {

			class ServerMessages {
			  public:
			    static const std::string INVALID_COMMAND;
			    static const std::string NICKNAME_ALREADY_EXISTS;
			    static const std::string ON_LOGOUT_SUFFIX;
			    static const std::string ON_LOGIN_SUFFIX;
			    static const std::string SERVER_SHUTDOWN;
			    static const std::string TOTAL_SCORE;
			};
		}
	}
}

#endif /*SERVER_GAME_MESSAGES_SERVERMESSAGES_H_*/
