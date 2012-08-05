# Agregamos un ejecutable llamado 'client' y especificamos sus fuentes.
# Cada vez que se agregue uno, debera agregarse aqui tambien.
add_executable (tamClient 
	main.cpp
	game/commands/command.cpp
	game/commands/commandfactory.cpp
	game/commands/availablesessionscommand.cpp
	game/commands/createsinglesessioncommand.cpp
	game/commands/createmultisessioncommand.cpp
	game/commands/feedbackcommand.cpp
	game/commands/joincommand.cpp
	game/commands/levelcommand.cpp
	game/commands/levelcompletedcommand.cpp
	game/commands/levelstartcommand.cpp
	game/commands/logincommand.cpp
	game/commands/messagecommand.cpp
	game/commands/exceptions/commandexception.cpp
	game/facade/commandfacade.cpp
	game/model/gameclient.cpp
	game/model/incomingmessagequeue.cpp
	game/model/message.cpp
	game/model/outcomingrequestqueue.cpp
	game/model/requestsender.cpp
	game/model/serverlistener.cpp
	game/model/session.cpp
	ui/controllers/initresponse.cpp
	ui/controllers/initwindowcontroller.cpp
	ui/controllers/levelmanager.cpp
	ui/controllers/gamewindowcontroller.cpp
	ui/controllers/sessiontreemodel.h
	ui/controllers/uimessages.cpp
	ui/widgets/toolbarexpander.cpp
)

execute_process(
	COMMAND ${CMAKE_COMMAND} -E copy
		${TAM_SOURCE_DIR}/src/client/ui/resources/feedbackWindow.glade
		${EXECUTABLE_OUTPUT_PATH}/view/feedbackWindow.glade
	COMMAND ${CMAKE_COMMAND} -E copy
		${TAM_SOURCE_DIR}/src/client/ui/resources/gameWindow.glade
		${EXECUTABLE_OUTPUT_PATH}/view/gameWindow.glade
	COMMAND ${CMAKE_COMMAND} -E copy
		${TAM_SOURCE_DIR}/src/client/ui/resources/dlgInitWindow.glade
		${EXECUTABLE_OUTPUT_PATH}/view/dlgInitWindow.glade
	)

# Linkeamos el ejecutable con las librerias correspondientes.
target_link_libraries (
	tamClient 
	ui
	game 
	common 
	${GTKMM_LIBRARIES} 
	${CAIROMM_LIBRARIES} 
	${LIBGLADEMM_LIBRARIES}
	${SIGCMM_LIBRARIES}
	-lpthread
)
 
