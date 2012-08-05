# Agregamos un ejecutable llamado 'server' y especificamos sus fuentes.
# Cada vez que se agregue uno, debera agregarse aqui tambien.
add_executable (tamServer 
	main.cpp
	server.cpp
	game/client/gameclient.cpp
	game/client/messagepool.cpp	
	game/client/messagereceiver.cpp	
	game/client/messagesender.cpp	
	game/commands/availablesessionscommand.cpp
	game/commands/command.h
	game/commands/commandfactory.cpp
	game/commands/createsinglesessioncommand.cpp
	game/commands/createmultisessioncommand.cpp	
	game/commands/feedbackcommand.cpp
	game/commands/joincommand.cpp
	game/commands/levelcommand.cpp
	game/commands/levelcompletedcommand.cpp
	game/commands/logincommand.cpp	
	game/commands/messagecommand.cpp
	game/commands/exceptions/commandexception.cpp
	game/gameserver.cpp
	game/levels/level.cpp
	game/levels/levelmanager.cpp
	game/levels/exceptions/nomorelevelsexception.cpp
	game/messages/servermessages.cpp
	game/sessions/gamesession.cpp
	game/sessions/gamesessionmanager.cpp
)

# Linkeamos el ejecutable con las librerias correspondientes.
target_link_libraries (tamServer common -lpthread)
 