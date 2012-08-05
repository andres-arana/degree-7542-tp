#include "logincommand.h"

#define LOGIN_REQUEST_CMD "/login "
#define LOGIN_SUCCESS "1"

using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

string LoginCommand::buildRequest() const {
	string loginRequest = LOGIN_REQUEST_CMD;
	loginRequest.append(this->params);
	return loginRequest;
}
		
void LoginCommand::executeResponse(GameClient* gameClient) {
	gameClient->setLoginSuccess(this->params == LOGIN_SUCCESS);
	Command::executeResponse(gameClient); 
}
