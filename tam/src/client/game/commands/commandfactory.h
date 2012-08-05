#ifndef CLIENT_GAME_COMMANDS_COMMANDFACTORY_H_
#define CLIENT_GAME_COMMANDS_COMMANDFACTORY_H_

#include <map>
#include "command.h"
#include "threads/locks/mutex.h"

#define MESSAGE_CMD "/msg"
#define LOGIN_CMD "/login"
#define JOIN_CMD "/join"
#define LEVEL_CMD "/level"
#define SESSIONS_CMD "/sessions"
#define CREATE_SINGLE_CMD "/createSingle"
#define CREATE_MULTI_CMD "/createMulti"
#define LEVEL_COMPLETED_CMD "/levelCompleted"
#define LEVEL_START_CMD "/levelStart"
#define FEEDBACK_CMD "/feedback"

namespace client {
	namespace game {
		namespace commands {
			/**
			 * Factory de Creacion de Comandos.
			 * @author Gabriel Raineri 
			 */
			class CommandFactory {
				private:
			    CommandFactory();
			    ~CommandFactory();
			    // No copiable.
			    CommandFactory(const CommandFactory &cf);
			    // No asignable.
			    CommandFactory& operator=(const CommandFactory &cf);
			    /**
			     * Como esta clase es un Singleton y es accedida por varios threads, 
			     * necesito sincronizar el acceso a recursos.
			     */		    
			    common::threads::locks::Mutex mutex;
			    /**
			     * Mapa de Comandos. Map<NombreComando, Puntero a Funcion Factory>
			     */   
			    std::map<std::string, Command* (*) ()> commandMap;
			    
			    static Command* createMsgCommand();
			    static Command* createLoginCommand();
			    static Command* createJoinCommand();
			    static Command* createLevelCommand();
			    static Command* createAvailableSessionsCommand();
			    static Command* createSingleSessionCommand();
			    static Command* createMultiSessionCommand();
			    static Command* createMarkLevelAsCompletedCommand();
			    static Command* createLevelStartCommand();
			    static Command* createFeedbackCommand();
			    
			  public:       
			    /**
			     * Devuelve la unica instancia de esta clase.
			     */
			    static CommandFactory& getInstance();     
			    /**
			     * Retorna un Comando dado su nombre.
			     * @throws CommandException en caso de que el comando no exista.
			     * @return El Comando.
			     */
			    Command* getCommandByName(const std::string& message);
			};
		}
	}
}

#endif /*CLIENT_GAME_COMMANDS_COMMANDFACTORY_H_*/
