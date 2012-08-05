#ifndef CLIENT_GAME_UI_GAMEWINDOWCONTROLLER_H_
#define CLIENT_GAME_UI_GAMEWINDOWCONTROLLER_H_

#include "levelmanager.h"
#include "../../game/model/gameclient.h"
#include "controllers/configurablerenderareacontroller.h"
#include "logic/gameengine.h"
#include "views/gamerenderarea.h"
#include "../widgets/toolbarexpander.h"
#include <gtkmm.h>
#include <libglademm/xml.h>

namespace client {
	namespace ui {
		namespace controllers {
			class GameWindowController {
				private:
					client::game::model::GameClient* gameClient;
					Glib::RefPtr<Gnome::Glade::Xml> refXml;
					Gtk::Window* gameWindow;
					Gtk::Window* feedbackWindow;
					Gtk::Frame* toolboxFrame;
					Gtk::Frame* actionsFrame;
					Gtk::Frame* simulationFrame;
					Gtk::RadioButton* metalBarRadio;
					Gtk::RadioButton* metalPlatformRadio;
					Gtk::RadioButton* ropeRadio;
					Gtk::RadioButton* canvasTapeRadio;
					Gtk::RadioButton* massRadio;
					Gtk::RadioButton* rocketRadio;
					Gtk::RadioButton* wheelRadio;
					Gtk::RadioButton* fixedPointRadio;
					Gtk::RadioButton* moveRadio;
					Gtk::RadioButton* connectRadio;
					Gtk::RadioButton* deleteRadio;
					Gtk::Button* simulateButton;
					Gtk::Button* stopButton;
					Gtk::Button* sendButton;
					Gtk::ToggleButton* dndButton;
					Gtk::Entry* chatEntry;
					Gtk::TextView* chatTextView;
					Gtk::ProgressBar* remTimeProgressBar;
					Gtk::Label* scoreLabel;
					Gtk::Label* totalSpentLabel;
					::game::logic::GameEngine gameEngine;
					::ui::views::GameRenderArea gameRenderArea;
					::ui::views::GameRenderArea opponentRenderArea;
					::ui::controllers::ConfigurableRenderAreaController gameAreaController;
					::game::serialization::BusinessDelegate serializationDelegate;
					::game::design::ElementContainer feedbackContainer;
					LevelManager levelManager;					
					widgets::ToolbarExpander toolbarExpander;
					bool multiplayer;
					
					// Levels
					void initLevel();
					
					// Widgets
					void initWidgets();
					
					// Bindings
					void bindSignals();
					
					// Timers
					sigc::slot<bool> chatMessagesSlot;
					sigc::slot<bool> levelsSlot;
					sigc::slot<bool> remTimeSlot;
					sigc::slot<bool> feedbackSlot;
					sigc::connection feedbackTimer;
					sigc::connection idleTimer;
					void initTimers();					
					
					// Events
					void onMetalBarRadioToggled();
					void onMetalPlatformRadioToggled();
					void onRopeRadioToggled();
					void onCanvasTapeRadioToggled();
					void onMassRadioToggled();
					void onRocketRadioToggled();
					void onWheelRadioToggled();
					void onFixedPointRadioToggled();
					void onMoveRadioToggled();
					void onConnectRadioToggled();
					void onDeleteRadioToggled();
					void onSimulateButtonClicked();
					void onStopButtonClicked();
					void onSendButtonClicked();
					void onChatEntryEnterPressed();
					void onUpdate();
					
					// ChatView
					void processChatEntryText();
					void writeToChatTextView(const Glib::ustring& text, 
							bool colorful = true);
					
					// Processes
					bool checkForIncomingMessages();
					bool checkForNewLevel();
					bool checkRemainingTime();
					bool feedback();
					void handleEndOfLevel();
					bool onIdle();
					
					void updateScoreInStatusBar(int totalScore);
					void updateTotalSpent();
					void enableGameArea(bool enable = true);
					void disableForSimulation(bool disable = true);
					
					void swapToDesignMode();
					void swapToRuntimeMode();
					void connectFeedback(bool connect = true);
					void levelTransition();
					void toggleExpander(
							::game::logic::properties::ElementProperties* properties,
							Gtk::Container& container);
				public:				
					GameWindowController(client::game::model::GameClient* gameClient, 
							bool multiplayer);
					~GameWindowController();
					
					void show();
			};
		}
	}
}

#endif /*CLIENT_GAME_UI_GAMEWINDOWCONTROLLER_H_*/
