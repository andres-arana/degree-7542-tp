#include "servermessages.h"

using namespace server::game::messages;
using namespace std;
    
const string ServerMessages::INVALID_COMMAND 
    = "El comando especificado es invalido.";
        
const string ServerMessages::NICKNAME_ALREADY_EXISTS 
    = "El nick ya esta siendo utilizado.";    
    
const string ServerMessages::ON_LOGOUT_SUFFIX
    = " se ha desconectado.";

const string ServerMessages::ON_LOGIN_SUFFIX
    = " se ha conectado.";

const string ServerMessages::SERVER_SHUTDOWN
    = "Se ha perdido la conexion con el servidor.";

const string ServerMessages::TOTAL_SCORE
		= "Puntaje Final de ";
