#include "commandfactory.h"
#include "messagecommand.h"
#include "logincommand.h"
#include "joincommand.h"
#include "levelcommand.h"
#include "availablesessionscommand.h"
#include "feedbackcommand.h"
#include "createsinglesessioncommand.h"
#include "createmultisessioncommand.h"
#include "levelcompletedcommand.h"
#include "levelstartcommand.h"
#include "exceptions/commandexception.h"
#include "threads/locks/lock.h"

using namespace client::game::commands;
using namespace client::game::commands::exceptions;
using namespace common::threads::locks;
using namespace std;

CommandFactory::CommandFactory() {
  // Inicializo el mapa de comandos con los punteros a funciones factory.
  this->commandMap[MESSAGE_CMD] = CommandFactory::createMsgCommand;
  this->commandMap[LOGIN_CMD] = CommandFactory::createLoginCommand;
  this->commandMap[JOIN_CMD] = CommandFactory::createJoinCommand;
  this->commandMap[LEVEL_CMD] = CommandFactory::createLevelCommand;
  this->commandMap[SESSIONS_CMD] = CommandFactory::createAvailableSessionsCommand;
  this->commandMap[CREATE_SINGLE_CMD] = CommandFactory::createSingleSessionCommand;
  this->commandMap[CREATE_MULTI_CMD] = CommandFactory::createMultiSessionCommand;
  this->commandMap[LEVEL_COMPLETED_CMD] = CommandFactory::createMarkLevelAsCompletedCommand;
  this->commandMap[LEVEL_START_CMD] = CommandFactory::createLevelStartCommand;
  this->commandMap[FEEDBACK_CMD] = CommandFactory::createFeedbackCommand;
}

CommandFactory::~CommandFactory() {
	
}

CommandFactory& CommandFactory::getInstance() {
  static CommandFactory instance;
  return instance;
}

Command* CommandFactory::createMsgCommand() {
	return new MessageCommand();
}

Command* CommandFactory::createLoginCommand() {
	return new LoginCommand();
}

Command* CommandFactory::createJoinCommand() {
	return new JoinCommand();
}

Command* CommandFactory::createLevelCommand() {
	return new LevelCommand();
}

Command* CommandFactory::createAvailableSessionsCommand() {
	return new AvailableSessionsCommand();
}

Command* CommandFactory::createSingleSessionCommand() {
	return new CreateSingleSessionCommand();
}

Command* CommandFactory::createMultiSessionCommand() {
	return new CreateMultiSessionCommand();
}

Command* CommandFactory::createMarkLevelAsCompletedCommand() {
	return new LevelCompletedCommand();
}

Command* CommandFactory::createLevelStartCommand() {
	return new LevelStartCommand();
}

Command* CommandFactory::createFeedbackCommand() {
	return new FeedbackCommand();
}

Command* CommandFactory::getCommandByName(const string& cmdName) {  
  Lock lock(this->mutex);
  Command* (*commandFactoryMethod) () = NULL;  
  commandFactoryMethod = this->commandMap[cmdName];  
  if (!commandFactoryMethod) {
    throw CommandException();
  }
  return commandFactoryMethod();
}
