# Creamos la libreria estatica common especificando los fuentes que contiene.
# Cada vez que se agregue uno, debera agregarse aqui tambien.
add_library (common 
	constants/gameconstants.cpp
	logger/tri_logger.cpp
	protocol/protocolsender.cpp
	protocol/protocolreceiver.cpp	
	sockets/data.cpp 
	sockets/tcpsocket.cpp
	sockets/exceptions/tcpsocketexception.cpp
	sockets/exceptions/tcpsocketconnectionclosedexception.cpp
	threads/locks/conditionalwait.cpp
	threads/locks/mutex.cpp
	threads/locks/lock.cpp
	threads/locks/readwritelock.cpp
	threads/locks/sharedreadlock.cpp
	threads/locks/exclusivewritelock.cpp	
	threads/thread.cpp
	utils/fileutils.cpp
	utils/math.cpp
	utils/stringutils.cpp	
)
	