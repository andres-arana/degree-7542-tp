#include "game/gameserver.h"
#include "sockets/exceptions/tcpsocketexception.h"
#include <iostream>

using namespace server::game;
using namespace common::sockets::exceptions;
using namespace std;

int main(int argc, char* argv[]) {
	try {
		GameServer gameServer;	
		if (argc == 2) {
			gameServer.startServer(argv[1]);
		} else {
			gameServer.startServer();
		}			
		cin.get();
		gameServer.shutdownServer();
	} catch (const TcpSocketException& e) {
		cerr << "Error en Servidor! " << e.what() << endl;
	}
}
