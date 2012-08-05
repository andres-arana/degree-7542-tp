#include "createsinglesessioncommand.h"

#define CREATE_SINGLE_REQUEST_CMD "/createSingle"

using namespace client::game::commands;
using namespace client::game::model;
using namespace std;

string CreateSingleSessionCommand::buildRequest() const {
	return CREATE_SINGLE_REQUEST_CMD;
}
		
void CreateSingleSessionCommand::executeResponse(GameClient* gameClient) {
	// No se espera respuesta del servidor.
}
