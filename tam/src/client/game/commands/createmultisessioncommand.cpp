#include "createmultisessioncommand.h"

#define CREATE_MULTI_REQUEST_CMD "/createMulti"

using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

string CreateMultiSessionCommand::buildRequest() const {
	return CREATE_MULTI_REQUEST_CMD;
}
		
void CreateMultiSessionCommand::executeResponse(GameClient* gameClient) {
	// No se espera respuesta del servidor.
}
