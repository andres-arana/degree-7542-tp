#ifndef CLIENT_GAME_UI_UIMESSAGES_H_
#define CLIENT_GAME_UI_UIMESSAGES_H_

#include <string>

namespace client {
	namespace ui {
		namespace controllers {
			class UIMessages {
				public:
					static const std::string CONNECTING_WITH_SERVER;
					static const std::string LOGGING_IN;
					static const std::string IP_AND_NICK_REQUIRED;
					static const std::string ENTERING_SESSION;
					static const std::string SESSION_MUST_BE_SELECTED;
					static const std::string RETRIEVING_AVAILABLE_SESSIONS;
					static const std::string NICKNAME_IN_USE;
					static const std::string CHOOSE_GAME_MODE;
					static const std::string INITIALIZING_GAME;
					static const std::string SESSION_IS_FULL;
					static const std::string WAITING_FOR_OPPONENT;
					static const std::string OPPONENT_CONNECTED;
					static const std::string NO_CONNECTION;
					static const std::string NO_MORE_LEVELS;
					static const std::string LOADING_LEVEL;
					static const std::string START_LEVEL;
					static const std::string TOTAL_SCORE;				
					static const std::string SECONDS;	
			};
		}
	}
}

#endif /*CLIENT_GAME_UI_UIMESSAGES_H_*/
