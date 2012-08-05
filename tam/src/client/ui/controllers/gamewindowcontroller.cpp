#include "gamewindowcontroller.h"
#include "uimessages.h"
#include "../../game/facade/commandfacade.h"
#include "../../game/model/message.h"
#include "../../game/model/incomingmessagequeue.h"
#include "controllers/controllers.h"
#include "views/blueprintrenderer.h"
#include "views/design/elementcontainerdesignrenderer.h"
#include "utils/stringutils.h"
#include <vector>

#define GLADE_GAME_WINDOW "view/gameWindow.glade"
#define GLADE_FEEDBACK_WINDOW "view/feedbackWindow.glade"
#define GAME_WINDOW_NAME "gameWindow"
#define FEEDBACK_WINDOW_NAME "feedbackWindow"
#define GAME_PANEL_VBOX "gamePanelVBox"
#define TOOLBOX_FRAME_NAME "toolboxFrame"
#define ACTIONS_FRAME_NAME "actionsFrame"
#define SIMULATION_FRAME_NAME "simulationFrame"
#define METAL_BAR_RADIO_NAME "metalBarRadio"
#define METAL_PLATFORM_RADIO_NAME "metalPlatformRadio"
#define ROPE_RADIO_NAME "ropeRadio"
#define CANVAS_TAPE_RADIO_NAME "canvasTapeRadio"
#define MASS_RADIO_NAME "massRadio"
#define ROCKET_RADIO_NAME "rocketRadio"
#define WHEEL_RADIO_NAME "wheelRadio"
#define FIXED_POINT_RADIO_NAME "fixedPointRadio"
#define MOVE_RADIO_NAME "moveRadio"
#define CONNECT_RADIO_NAME "connectRadio"
#define DELETE_RADIO_NAME "deleteRadio"
#define SIMULATE_BUTTON_NAME "simulateButton"
#define STOP_BUTTON_NAME "stopButton"
#define SEND_BUTTON_NAME "sendButton"
#define DND_BUTTON_NAME "dndButton"
#define CHAT_ENTRY_NAME "chatEntry"
#define CHAT_TEXTVIEW_NAME "chatTextView"
#define REM_TIME_PROGRESS_BAR "remTimeProgressBar"
#define STATUS_BAR_NAME "statusBar"
#define FEEDBACK_ALIGNMENT_NAME "feedbackAlignment"
#define SCORE_LABEL_NAME "scoreLabel"
#define TOTAL_SPENT_LABEL_NAME "totalSpentLabel"
#define SERVER_MESSAGES_COLOR "blue"
// Constante de Tiempo
#define HALF_SECOND 500
#define THREE_SECONDS 3000

using namespace client::game::model;
using namespace client::game::facade;
using namespace client::ui::controllers;
using namespace client::ui::widgets;
using namespace common::utils;
using namespace game::design;
using namespace game::logic::properties;
using namespace ui::controllers;
using namespace ui::views;
using namespace ui::views::design;
using namespace std;

GameWindowController::GameWindowController(GameClient* gameClient, bool multiplayer) :
	gameClient(gameClient),
	gameWindow(NULL),
	toolboxFrame(NULL),
	actionsFrame(NULL),
	simulationFrame(NULL),
	metalBarRadio(NULL),
	metalPlatformRadio(NULL),
	ropeRadio(NULL),
	canvasTapeRadio(NULL),
	massRadio(NULL),
	rocketRadio(NULL),
	wheelRadio(NULL),
	fixedPointRadio(NULL),
	moveRadio(NULL),
	connectRadio(NULL),
	deleteRadio(NULL),
	sendButton(NULL),
	dndButton(NULL),
	chatEntry(NULL),
	chatTextView(NULL),
	opponentRenderArea(0.5),
	gameAreaController(gameRenderArea),
	levelManager(gameEngine, gameRenderArea),
	multiplayer(multiplayer) {

	this->initWidgets();
	this->bindSignals();
	this->initLevel();
	this->initTimers();
}

GameWindowController::~GameWindowController() {
	if (this->gameWindow) delete this->gameWindow;
}

void GameWindowController::initLevel() {
	CommandFacade::getNextLevel();
}

void GameWindowController::initTimers() {
	this->levelsSlot
			= sigc::mem_fun(*this, &GameWindowController::checkForNewLevel);
	this->chatMessagesSlot
			= sigc::mem_fun(*this, &GameWindowController::checkForIncomingMessages);
	this->remTimeSlot
			= sigc::mem_fun(*this, &GameWindowController::checkRemainingTime);
	this->feedbackSlot
			= sigc::mem_fun(*this, &GameWindowController::feedback);
	Glib::signal_timeout().connect(this->levelsSlot, HALF_SECOND);
	Glib::signal_timeout().connect(this->chatMessagesSlot, HALF_SECOND);
}

void GameWindowController::initWidgets() {
	Gtk::VBox* gamePanelVBox = NULL;

	this->refXml = Gnome::Glade::Xml::create(GLADE_GAME_WINDOW);
	this->refXml->get_widget(GAME_WINDOW_NAME, this->gameWindow);

	this->refXml->get_widget(TOOLBOX_FRAME_NAME, this->toolboxFrame);
	this->refXml->get_widget(ACTIONS_FRAME_NAME, this->actionsFrame);
	this->refXml->get_widget(SIMULATION_FRAME_NAME, this->simulationFrame);

	this->refXml->get_widget(METAL_BAR_RADIO_NAME, this->metalBarRadio);
	this->metalBarRadio->set_mode(false);
	Gtk::RadioButton::Group group = this->metalBarRadio->get_group();

	this->refXml->get_widget(METAL_PLATFORM_RADIO_NAME, this->metalPlatformRadio);
	this->metalPlatformRadio->set_mode(false);
	this->metalPlatformRadio->set_group(group);

	this->refXml->get_widget(ROPE_RADIO_NAME, this->ropeRadio);
	this->ropeRadio->set_mode(false);
	this->ropeRadio->set_group(group);

	this->refXml->get_widget(CANVAS_TAPE_RADIO_NAME, this->canvasTapeRadio);
	this->canvasTapeRadio->set_mode(false);
	this->canvasTapeRadio->set_group(group);

	this->refXml->get_widget(MASS_RADIO_NAME, this->massRadio);
	this->massRadio->set_mode(false);
	this->massRadio->set_group(group);

	this->refXml->get_widget(ROCKET_RADIO_NAME, this->rocketRadio);
	this->rocketRadio->set_mode(false);
	this->rocketRadio->set_group(group);

	this->refXml->get_widget(WHEEL_RADIO_NAME, this->wheelRadio);
	this->wheelRadio->set_mode(false);
	this->wheelRadio->set_group(group);

	this->refXml->get_widget(FIXED_POINT_RADIO_NAME, this->fixedPointRadio);
	this->fixedPointRadio->set_mode(false);
	this->fixedPointRadio->set_group(group);

	this->refXml->get_widget(MOVE_RADIO_NAME, this->moveRadio);
	this->moveRadio->set_mode(false);
	this->moveRadio->set_group(group);

	this->refXml->get_widget(CONNECT_RADIO_NAME, this->connectRadio);
	this->connectRadio->set_mode(false);
	this->connectRadio->set_group(group);

	this->refXml->get_widget(DELETE_RADIO_NAME, this->deleteRadio);
	this->deleteRadio->set_mode(false);
	this->deleteRadio->set_group(group);

	this->refXml->get_widget(SIMULATE_BUTTON_NAME, this->simulateButton);
	this->refXml->get_widget(STOP_BUTTON_NAME, this->stopButton);

	this->refXml->get_widget(SEND_BUTTON_NAME, this->sendButton);
	this->refXml->get_widget(DND_BUTTON_NAME, this->dndButton);
	this->refXml->get_widget(CHAT_ENTRY_NAME, this->chatEntry);
	this->refXml->get_widget(CHAT_TEXTVIEW_NAME, this->chatTextView);

	this->refXml->get_widget(REM_TIME_PROGRESS_BAR, this->remTimeProgressBar);
	this->remTimeProgressBar->set_fraction(0);

	this->refXml->get_widget(SCORE_LABEL_NAME, this->scoreLabel);
	this->refXml->get_widget(TOTAL_SPENT_LABEL_NAME, this->totalSpentLabel);
	this->updateScoreInStatusBar(0);

	this->refXml->get_widget(GAME_PANEL_VBOX, gamePanelVBox);
	gamePanelVBox->add(this->gameRenderArea);
	gamePanelVBox->show_all();

	if (this->multiplayer) {
		Gtk::Alignment* feedbackAlignment = NULL;
		this->refXml = Gnome::Glade::Xml::create(GLADE_FEEDBACK_WINDOW);
		this->refXml->get_widget(FEEDBACK_WINDOW_NAME, this->feedbackWindow);
		this->refXml->get_widget(FEEDBACK_ALIGNMENT_NAME, feedbackAlignment);
		this->opponentRenderArea.addRendererToLayer(
				GameRenderArea::ElementDesignLayer,
				new ElementContainerDesignRenderer(this->feedbackContainer));
		this->feedbackContainer.designModified().connect(
				sigc::mem_fun(this->opponentRenderArea, &GameRenderArea::redraw));
		this->opponentRenderArea.addRendererToLayer(GameRenderArea::BackgroundLayer,
				new BlueprintRenderer());
		feedbackAlignment->add(this->opponentRenderArea);
		feedbackAlignment->show_all();
		this->feedbackWindow->set_transient_for(*(this->gameWindow));
		this->feedbackWindow->show_all();
	}
}

void GameWindowController::bindSignals() {
  this->metalBarRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onMetalBarRadioToggled));

	this->metalPlatformRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onMetalPlatformRadioToggled));

	this->ropeRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onRopeRadioToggled));

	this->canvasTapeRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onCanvasTapeRadioToggled));

	this->massRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onMassRadioToggled));

	this->rocketRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onRocketRadioToggled));

	this->wheelRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onWheelRadioToggled));

	this->fixedPointRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onFixedPointRadioToggled));

	this->moveRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onMoveRadioToggled));
	this->moveRadio->set_active();

	this->connectRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onConnectRadioToggled));

	this->deleteRadio->signal_toggled().connect(sigc::mem_fun(
			*this, &GameWindowController::onDeleteRadioToggled));

	this->simulateButton->signal_clicked().connect(sigc::mem_fun(
			*this, &GameWindowController::onSimulateButtonClicked));

	this->stopButton->signal_clicked().connect(sigc::mem_fun(
			*this, &GameWindowController::onStopButtonClicked));

	this->sendButton->signal_clicked().connect(sigc::mem_fun(
			*this, &GameWindowController::onSendButtonClicked));

	this->chatEntry->signal_activate().connect(sigc::mem_fun(
			*this, &GameWindowController::onChatEntryEnterPressed));

	this->gameEngine.designModified().connect(
			sigc::mem_fun(*this, &GameWindowController::onUpdate));
	this->gameEngine.runtimeModified().connect(
			sigc::mem_fun(*this, &GameWindowController::onUpdate));
	this->gameEngine.stateModified().connect(
			sigc::mem_fun(*this, &GameWindowController::onUpdate));
	this->gameEngine.endOfLevel().connect(
			sigc::mem_fun(*this, &GameWindowController::handleEndOfLevel));
	this->gameEngine.getDesignToolbox().modified().connect(
			sigc::mem_fun(this->toolbarExpander, &ToolbarExpander::updateValues));
	this->gameEngine.getDesignToolbox().modified().connect(
			sigc::mem_fun(*this, &GameWindowController::updateTotalSpent));
}

void GameWindowController::toggleExpander(ElementProperties* properties,
		Gtk::Container& container) {

	this->toolbarExpander.setElementProperties(properties);
	this->toolbarExpander.moveToContainer(container);
	this->toolbarExpander.updateValues();
}

void GameWindowController::onMetalBarRadioToggled() {
	if (this->metalBarRadio->get_active()) {
		this->toggleExpander(this->gameEngine.getDesignToolbox().getMetalBarProperties(),
				*(this->metalBarRadio->get_parent()));

		this->gameAreaController.configureCurrentHandler(
				new MetalBarCreatorInputHandler(this->gameEngine.getDesignToolbox(), this->gameEngine));
	}
}

void GameWindowController::onMetalPlatformRadioToggled() {
	if (this->metalPlatformRadio->get_active()) {
		this->toggleExpander(this->gameEngine.getDesignToolbox().getMetalPlatformProperties(),
				*(this->metalPlatformRadio->get_parent()));

		this->gameAreaController.configureCurrentHandler(
				new MetalPlatformCreatorInputHandler(this->gameEngine.getDesignToolbox(), this->gameEngine));
	}
}

void GameWindowController::onRopeRadioToggled() {
	if (this->ropeRadio->get_active()) {
		this->toggleExpander(this->gameEngine.getDesignToolbox().getRopeProperties(),
				*(this->ropeRadio->get_parent()));

		this->gameAreaController.configureCurrentHandler(
				new RopeCreatorInputHandler(this->gameEngine.getDesignToolbox(), this->gameEngine));
	}
}

void GameWindowController::onCanvasTapeRadioToggled() {
	if (this->canvasTapeRadio->get_active()) {
		this->toggleExpander(this->gameEngine.getDesignToolbox().getCanvasTapeProperties(),
				*(this->canvasTapeRadio->get_parent()));

		this->gameAreaController.configureCurrentHandler(
				new CanvasTapeCreatorInputHandler(this->gameEngine.getDesignToolbox(), this->gameEngine));
	}
}

void GameWindowController::onMassRadioToggled() {
	if (this->massRadio->get_active()) {
		this->toggleExpander(this->gameEngine.getDesignToolbox().getMassProperties(),
				*(this->massRadio->get_parent()));

		this->gameAreaController.configureCurrentHandler(
				new MassCreatorInputHandler(this->gameEngine.getDesignToolbox(), this->gameEngine));
	}
}

void GameWindowController::onRocketRadioToggled() {
	if (this->rocketRadio->get_active()) {
		this->toggleExpander(this->gameEngine.getDesignToolbox().getRocketProperties(),
				*(this->rocketRadio->get_parent()));

		this->gameAreaController.configureCurrentHandler(
				new RocketCreatorInputHandler(this->gameEngine.getDesignToolbox(), this->gameEngine));
	}
}

void GameWindowController::onWheelRadioToggled() {
	if (this->wheelRadio->get_active()) {
		this->toggleExpander(this->gameEngine.getDesignToolbox().getWheelProperties(),
				*(this->wheelRadio->get_parent()));

		this->gameAreaController.configureCurrentHandler(
				new WheelCreatorInputHandler(this->gameEngine.getDesignToolbox(), this->gameEngine));
	}
}

void GameWindowController::onFixedPointRadioToggled() {
	if (this->fixedPointRadio->get_active()) {
		this->toggleExpander(this->gameEngine.getDesignToolbox().getFixedPointProperties(),
				*(this->fixedPointRadio->get_parent()));

		this->gameAreaController.configureCurrentHandler(
				new FixedPointCreatorInputHandler(this->gameEngine.getDesignToolbox(), this->gameEngine));
	}
}

void GameWindowController::onMoveRadioToggled() {
	if (this->moveRadio->get_active()) {
		this->gameAreaController.configureCurrentHandler(
			new MoveInputHandler(this->gameRenderArea, this->gameEngine));
	}
}

void GameWindowController::onConnectRadioToggled() {
	if (this->connectRadio->get_active()) {
		this->gameAreaController.configureCurrentHandler(
				new ConnectInputHandler(this->gameRenderArea, this->gameEngine));
	}

}

void GameWindowController::onDeleteRadioToggled() {
	if (this->deleteRadio->get_active()) {
		this->gameAreaController.configureCurrentHandler(
				new DeleteInputHandler(this->gameEngine));
	}
}

void GameWindowController::onSimulateButtonClicked() {
	this->swapToRuntimeMode();
	this->idleTimer = Glib::signal_idle().connect(
			sigc::mem_fun(*this, &GameWindowController::onIdle));
}

void GameWindowController::onStopButtonClicked() {
	this->idleTimer.disconnect();
	this->swapToDesignMode();
}

void GameWindowController::onSendButtonClicked() {
	this->processChatEntryText();
}

void GameWindowController::onChatEntryEnterPressed() {
	this->processChatEntryText();
}

void GameWindowController::processChatEntryText() {
	Glib::ustring entryText = this->chatEntry->get_text();
  if (entryText.empty()) return;
	if (!this->gameClient->isConnected()) {
		this->writeToChatTextView(UIMessages::NO_CONNECTION + "\n");
  } else {
		CommandFacade::sendChatMessage(entryText.raw());
  }
  this->chatEntry->set_text("");
}

void GameWindowController::writeToChatTextView(
		const Glib::ustring& text, bool colorful) {

  Glib::RefPtr<Gtk::TextBuffer> buffer = this->chatTextView->get_buffer();
 	Glib::RefPtr<Gtk::TextBuffer::Mark> endMark = buffer->create_mark(buffer->end());
 	buffer->insert(buffer->end(), text);

	if (colorful) {
		Glib::RefPtr<Gtk::TextBuffer::TagTable> refTagTable = buffer->get_tag_table();

		Glib::RefPtr<Gtk::TextBuffer::Tag> refTagBlue = Gtk::TextBuffer::Tag::create();
		refTagBlue->property_foreground() = SERVER_MESSAGES_COLOR;
		refTagTable->add(refTagBlue);
		buffer->apply_tag(refTagBlue, endMark->get_iter(), buffer->end());

		Glib::RefPtr<Gtk::TextBuffer::Tag> refTagBold = Gtk::TextBuffer::Tag::create();
		refTagBold->property_weight() = Pango::WEIGHT_BOLD;
		refTagTable->add(refTagBold);
		buffer->apply_tag(refTagBold, endMark->get_iter(), buffer->end());
	}
  // "Scrolleo" a la ultima linea.
  this->chatTextView->scroll_to(buffer->create_mark(buffer->end()));
}

bool GameWindowController::checkForIncomingMessages() {
  Glib::ustring textToDisplay = "";
  vector<const Message*>::iterator i;
  vector<const Message*>* messages
      = IncomingMessageQueue::getInstance().getAllQueuedMessages();
  for (i = messages->begin(); i != messages->end(); ++i) {
    if (!(*i)->getFrom().empty()) {
      if (this->dndButton->get_active()) {
      	delete (*i);
      	continue;
      }
      textToDisplay = (*i)->getFrom() + ": ";
    }
    textToDisplay.append((*i)->getText()).append("\n");
    this->writeToChatTextView(textToDisplay, (*i)->getFrom().empty());
    textToDisplay.clear();
    delete (*i);
  }
  delete messages;
  return true;
}

bool GameWindowController::onIdle() {
	this->gameEngine.doTimeStep();
	return true;
}

bool GameWindowController::checkForNewLevel() {
	if (this->gameClient->wasResponseReceived()) {
		if (this->gameClient->hasMoreLevels()) {
			if (this->gameClient->hasLevelToStart()) {
				this->writeToChatTextView(UIMessages::LOADING_LEVEL + "\n");
				this->levelTransition();
				this->gameClient->resetStatus();
				this->writeToChatTextView(UIMessages::START_LEVEL + "\n");
				return false;
			}
		} else {
			this->enableGameArea(false);
			this->writeToChatTextView(UIMessages::NO_MORE_LEVELS + "\n");
			this->gameClient->resetStatus();
			return false;
		}
	}
	return true;
}

bool GameWindowController::checkRemainingTime() {
	this->remTimeProgressBar->set_fraction(
			this->gameEngine.getElapsedTimePercentage());
	string remTime
			= StringUtils::numberToString<int>(this->gameEngine.getRemainingTime());
	remTime.append(UIMessages::SECONDS);
	this->remTimeProgressBar->set_text(remTime);
	return !(this->gameEngine.isLevelFailed() || this->gameEngine.isLevelCompleted());
}

bool GameWindowController::feedback() {
	if (this->gameClient->wasResponseReceived()) {
		string feedback = this->gameClient->getFeedbackStr();
		if (feedback.length()) {
			this->feedbackContainer.clearElements();
			this->serializationDelegate.unserialize(feedback, this->feedbackContainer);
			this->gameClient->resetStatus();
		}
	}
	CommandFacade::sendFeedback(
			this->serializationDelegate.serialize(this->gameEngine));
	return true;
}

void GameWindowController::handleEndOfLevel() {
	this->idleTimer.disconnect();
	if (this->gameEngine.isLevelCompleted()) {
		int score = this->gameEngine.calculateScore();
		this->gameClient->addScore(score);
		string scoreStr = StringUtils::numberToString<int>(score);
		this->updateScoreInStatusBar(this->gameClient->getTotalScore());
		CommandFacade::markLevelAsCompleted(scoreStr);
	} else {
		CommandFacade::markLevelAsFailed();
	}
	this->connectFeedback(false);
	CommandFacade::getNextLevel();
	Glib::signal_timeout().connect(this->levelsSlot, HALF_SECOND);
}

void GameWindowController::updateScoreInStatusBar(int totalScore) {
	string scoreStr = StringUtils::numberToString<int>(totalScore);
	this->scoreLabel->set_text(scoreStr);
}

void GameWindowController::updateTotalSpent() {
	string totalSpent = StringUtils::numberToString<int>(
			this->gameEngine.getDesignToolbox().calculateTotalSpent());
	this->totalSpentLabel->set_text(totalSpent);
}

void GameWindowController::enableGameArea(bool enable) {
	this->toolboxFrame->set_sensitive(enable);
	this->actionsFrame->set_sensitive(enable);
	this->simulationFrame->set_sensitive(enable);
	this->gameRenderArea.set_sensitive(enable);
	this->stopButton->set_sensitive(!enable);
}

void GameWindowController::disableForSimulation(bool disable) {
	this->toolboxFrame->set_sensitive(!disable);
	this->actionsFrame->set_sensitive(!disable);
	this->simulateButton->set_sensitive(!disable);
	this->stopButton->set_sensitive(disable);
	this->gameRenderArea.set_sensitive(!disable);
}

void GameWindowController::onUpdate() {
	this->gameRenderArea.redraw();
}

void GameWindowController::swapToDesignMode() {
	this->disableForSimulation(false);
	this->gameEngine.swapToDesignMode();
	this->gameRenderArea.restoreLayersState();
	this->connectFeedback();
}

void GameWindowController::swapToRuntimeMode() {
	this->disableForSimulation();
	this->gameEngine.swapToRuntimeMode();
	this->gameRenderArea.saveLayersState();
	this->gameRenderArea.swapToRuntimeMode();
	this->connectFeedback(false);
}

void GameWindowController::levelTransition() {
	this->remTimeProgressBar->set_fraction(0);
	this->gameEngine.clearEngine();
	this->gameRenderArea.disposeRenderers();
	this->levelManager.loadLevel();
	this->swapToDesignMode();
	this->moveRadio->set_active();
	Glib::signal_timeout().connect(this->remTimeSlot, HALF_SECOND);
}

void GameWindowController::connectFeedback(bool connect) {
	if (this->multiplayer) {
		if (connect) {
			this->feedbackTimer = Glib::signal_timeout().connect(
					this->feedbackSlot, THREE_SECONDS);
		} else {
			this->feedbackTimer.disconnect();
		}
	}
}

void GameWindowController::show() {
	Gtk::Main::run(*this->gameWindow);
}
