#include "initwindowcontroller.h"
#include "uimessages.h"
#include "../../game/facade/commandfacade.h"
#include "../../game/model/exceptions/connectionexception.h"
#include "logger/tri_logger.h"
#include <libglademm.h> 

#define GLADE_INIT_WINDOW "view/dlgInitWindow.glade"
// Constantes para Widgets
#define INIT_WINDOW "initWindow"
#define CONNECT_BUTTON "connectButton"
#define REFRESH_BUTTON "refreshButton"
#define SINGLE_SESSION_BUTTON "singleSessionButton"
#define MULTI_SESSION_BUTTON "multiSessionButton"
#define JOIN_SESSION_BUTTON "joinButton"
#define EXIT_BUTTON "exitButton"
#define IP_ENTRY "ipEntry"
#define NICK_ENTRY "nickEntry"
#define MESSAGE_LABEL "messageLabel"
#define CONNECTION_FRAME "connectionFrame"
#define SESSION_TREE "sessionTreeView"
// Constante de Tiempo
#define HALF_SECOND 500

using namespace client::ui::controllers;
using namespace client::game::model;
using namespace client::game::model::exceptions;
using namespace client::game::facade;
using namespace std;

InitWindowController::InitWindowController(GameClient* gameClient) : 
	gameClient(gameClient),
	refXml(NULL), 
	initWindow(NULL),
	messageLabel(NULL),
	connectionFrame(NULL),
	ipEntry(NULL),
	nickEntry(NULL),
	sessionTree(NULL),
	singleSessionButton(NULL),
	multiSessionButton(NULL),
	joinSessionButton(NULL),
	playGame(false),
	multiplayer(false) {
	  	
	this->initWidgets();
	this->enableActionButtons(false);
	this->initSlots();
	this->bindSignals();
}

InitWindowController::~InitWindowController() {
	if (this->initWindow) delete this->initWindow;
}

void InitWindowController::initWidgets() {
	this->refXml = Gnome::Glade::Xml::create(GLADE_INIT_WINDOW);
	this->refXml->get_widget(INIT_WINDOW, this->initWindow);
	this->refXml->get_widget(MESSAGE_LABEL, this->messageLabel);
	this->refXml->get_widget(CONNECTION_FRAME, this->connectionFrame);
	this->refXml->get_widget(IP_ENTRY, this->ipEntry);
	this->refXml->get_widget(NICK_ENTRY, this->nickEntry);
	this->refXml->get_widget(SESSION_TREE, this->sessionTree);
	this->refXml->get_widget(REFRESH_BUTTON, this->refreshButton);
	this->refXml->get_widget(SINGLE_SESSION_BUTTON, this->singleSessionButton);
	this->refXml->get_widget(MULTI_SESSION_BUTTON, this->multiSessionButton);
	this->refXml->get_widget(JOIN_SESSION_BUTTON, this->joinSessionButton);
	this->refTreeModel = Gtk::ListStore::create(this->sessionTreeModel);
	this->sessionTree->set_model(this->refTreeModel);
	this->sessionTree->append_column("ID", this->sessionTreeModel.idCol);
	this->sessionTree->append_column("Nombre", this->sessionTreeModel.nameCol);
}

void InitWindowController::enableActionButtons(bool enable) {
	this->refreshButton->set_sensitive(enable);
	this->singleSessionButton->set_sensitive(enable);
	this->multiSessionButton->set_sensitive(enable);
	this->joinSessionButton->set_sensitive(enable);
}

void InitWindowController::initSlots() {
	this->loginSlot = sigc::mem_fun(*this, 
			&InitWindowController::checkForLoginResponse);
	this->sessionsSlot = sigc::mem_fun(*this, 
			&InitWindowController::checkForSessionsResponse);
	this->joinSlot = sigc::mem_fun(*this, 
			&InitWindowController::checkForJoinResponse);
	this->opponentSlot = sigc::mem_fun(*this, 
			&InitWindowController::checkForOpponentResponse);
}

void InitWindowController::bindSignals() {
	this->bindConnectButton();
	this->bindRefreshButton();
	this->bindSingleSessionButton();
	this->bindMultiSessionButton();
	this->bindJoinSessionButton();
	this->bindExitButton();
	this->bindDefault();
}

void InitWindowController::bindConnectButton() {
	Gtk::Button* connectButton = NULL;
	refXml->get_widget(CONNECT_BUTTON, connectButton);
  connectButton->signal_clicked().connect(sigc::mem_fun
  		(*this, &InitWindowController::onConnectButtonClicked));
}

void InitWindowController::bindRefreshButton() {
 this->refreshButton->signal_clicked().connect(sigc::mem_fun
		(*this, &InitWindowController::onRefreshButtonClicked));
}	 

void InitWindowController::bindSingleSessionButton() {
  this->singleSessionButton->signal_clicked().connect(sigc::mem_fun
  		(*this, &InitWindowController::onSingleSessionButtonClicked));
}

void InitWindowController::bindMultiSessionButton() {
  this->multiSessionButton->signal_clicked().connect(sigc::mem_fun
  		(*this, &InitWindowController::onMultiSessionButtonClicked));
}

void InitWindowController::bindJoinSessionButton() {
  this->joinSessionButton->signal_clicked().connect(sigc::mem_fun
  		(*this, &InitWindowController::onJoinSessionButtonClicked));
}

void InitWindowController::bindExitButton() {
	Gtk::Button* exitButton = NULL;
	refXml->get_widget(EXIT_BUTTON, exitButton);
  exitButton->signal_clicked().connect(sigc::mem_fun
  		(*this, &InitWindowController::onExitButtonClicked));  
}

void InitWindowController::bindDefault() {
	this->ipEntry->signal_activate().connect(sigc::mem_fun(
			*this, &InitWindowController::onConnectButtonClicked));
	
	this->nickEntry->signal_activate().connect(sigc::mem_fun(
			*this, &InitWindowController::onConnectButtonClicked));						
}

void InitWindowController::onConnectButtonClicked() {
	Gtk::Entry* nickEntry = NULL;
	this->refXml->get_widget(NICK_ENTRY, nickEntry);
	
	Glib::ustring ipText = this->ipEntry->get_text();
	Glib::ustring nickText = nickEntry->get_text();
	if (!ipText.empty() && !nickText.empty()) {
		try {
			this->connectionFrame->set_sensitive(false);			
			this->messageLabel->set_text(UIMessages::CONNECTING_WITH_SERVER);
			if (!this->gameClient->isConnected()) {
				this->gameClient->connectToGameServer(ipText.raw());
			}
			this->messageLabel->set_text(UIMessages::LOGGING_IN);
			CommandFacade::login(nickText.raw());
			this->timeoutTimer = Glib::signal_timeout().connect(
					this->loginSlot, HALF_SECOND);						
		} catch(const ConnectionException& e) {
			this->connectionFrame->set_sensitive(true);
			this->ipEntry->grab_focus(); 
			this->messageLabel->set_text(e.what());
		}
	} else {
		this->messageLabel->set_text(UIMessages::IP_AND_NICK_REQUIRED);
	}
}

void InitWindowController::onRefreshButtonClicked() {
	this->retrieveAvailableSessions();
}

void InitWindowController::onSingleSessionButtonClicked() {
	this->enableActionButtons(false);
	CommandFacade::createSinglePlayerSession();
	this->multiplayer = false;
	this->setPlayGame(UIMessages::INITIALIZING_GAME);
}

void InitWindowController::onMultiSessionButtonClicked() {
	this->enableActionButtons(false);
	CommandFacade::createMultiPlayerSession();
	this->messageLabel->set_text(UIMessages::WAITING_FOR_OPPONENT);
	this->timeoutTimer = Glib::signal_timeout().connect(
			this->opponentSlot, HALF_SECOND);
}

void InitWindowController::onJoinSessionButtonClicked() {	
	Glib::RefPtr<Gtk::TreeSelection> refTreeSelection = 
			this->sessionTree->get_selection();
	Gtk::TreeModel::iterator iter = refTreeSelection->get_selected();
	if (iter) {
		this->enableActionButtons(false);
		// Hay una fila seleccionada.
  	Gtk::TreeModel::Row row = *iter;
  	CommandFacade::joinSession(row[this->sessionTreeModel.idCol]);
  	this->messageLabel->set_text(UIMessages::ENTERING_SESSION);
		this->timeoutTimer = Glib::signal_timeout().connect(
				this->joinSlot, HALF_SECOND);
	} else {
		this->messageLabel->set_text(UIMessages::SESSION_MUST_BE_SELECTED);
	}
}

void InitWindowController::onExitButtonClicked() {
	this->initWindow->hide();
}

void InitWindowController::retrieveAvailableSessions() {
	this->messageLabel->set_text(UIMessages::RETRIEVING_AVAILABLE_SESSIONS);
	CommandFacade::getAvailableSessions();
	this->timeoutTimer.disconnect();
	this->timeoutTimer = Glib::signal_timeout().connect(
			this->sessionsSlot, HALF_SECOND);
}

bool InitWindowController::checkForLoginResponse() {
	if (this->gameClient->wasResponseReceived()) {
		if (this->gameClient->isLogged()) {
			this->retrieveAvailableSessions();		
		} else {
			this->messageLabel->set_text(UIMessages::NICKNAME_IN_USE);
			this->connectionFrame->set_sensitive(true);
			this->ipEntry->set_sensitive(false);
			this->nickEntry->grab_focus();
		}
		this->gameClient->resetStatus();
		return false;
	}
	return true;
}

bool InitWindowController::checkForSessionsResponse() {
	if (this->gameClient->wasResponseReceived()) {
		list<Session*>* sessions = this->gameClient->getAvailableSessions();
		this->enableActionButtons(true);
		if (sessions->empty()) {
			this->joinSessionButton->set_sensitive(false);
		}
		this->populateTreeview(sessions);
		this->messageLabel->set_text(UIMessages::CHOOSE_GAME_MODE);
		this->gameClient->resetStatus();
		return false;
	}
	return true;
}

void InitWindowController::populateTreeview(list<Session*>* sessionList) {
	this->refTreeModel->clear();
	list<Session*>::const_iterator i;		
	for (i = sessionList->begin(); i != sessionList->end(); ++i) {
		Gtk::TreeModel::Row row = *(this->refTreeModel->append());
		row[sessionTreeModel.idCol] = (*i)->getId();
		row[sessionTreeModel.nameCol] = (*i)->getName();
	}	
}

bool InitWindowController::checkForJoinResponse() {
	if (this->gameClient->wasResponseReceived()) {
		if (this->gameClient->isJoined()) {
			this->multiplayer = true;
			this->setPlayGame(UIMessages::INITIALIZING_GAME);			
		} else {
			// En el lapso "justo" otro jugador se unio a la sesion.
			this->messageLabel->set_text(UIMessages::SESSION_IS_FULL);
			this->enableActionButtons(true);
		}
		this->gameClient->resetStatus();
		return false;
	}
	return true;
}

bool InitWindowController::checkForOpponentResponse() {
	if (this->gameClient->wasResponseReceived()) {
		if (this->gameClient->isOpponentConnected()) {
			this->multiplayer = true;
			this->setPlayGame(
					UIMessages::OPPONENT_CONNECTED + UIMessages::INITIALIZING_GAME);
		}
		return false;
	}
	return true;
}

void InitWindowController::setPlayGame(const string& textToShow) {
	this->messageLabel->set_text(textToShow);
	this->playGame = true;
	this->initWindow->hide();
}

InitResponse InitWindowController::show() {
	Gtk::Main::run(*this->initWindow);
	return InitResponse(!this->playGame, this->multiplayer);
}
