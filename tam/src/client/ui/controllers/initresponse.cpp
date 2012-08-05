#include "initresponse.h"

using namespace client::ui::controllers;

InitResponse::InitResponse(bool exited, bool multiplayer) :
	exited(exited),
	multiplayer(multiplayer) {
		
}

bool InitResponse::getExited() const {
	return this->exited;
}

bool InitResponse::getMultiplayerSession() const {
	return this->multiplayer;
}
