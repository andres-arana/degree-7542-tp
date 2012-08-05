#include "logincommand.h"
#include "../sessions/gamesessionmanager.h"
#include "logger/tri_logger.h"

#define LOGIN_RESPONSE_CMD "/login "
#define SUCCESS_FLAG "1"
#define ERROR_FLAG "0"

using namespace server::game::commands;
using namespace server::game::sessions;
using namespace std;

void LoginCommand::execute(
		client::GameClient* gameClient, const string& loginName) {

  string loginResponse = LOGIN_RESPONSE_CMD;	
	if (GameSessionManager::getInstance().isNickInUse(loginName)) {
		loginResponse.append(ERROR_FLAG);
	} else {
	  loginResponse.append(SUCCESS_FLAG);
  	gameClient->setNick(loginName);      
  	TRI_LOG_STR("LoginCommand - " + loginName + " se logueo.");
	}			
	gameClient->sendMessage(loginResponse);
}
