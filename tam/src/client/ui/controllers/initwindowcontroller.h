#ifndef CLIENTE_GAME_UI_INITWINDOWCONTROLLER_H_
#define CLIENTE_GAME_UI_INITWINDOWCONTROLLER_H_

#include "initresponse.h"
#include "../../game/model/gameclient.h"
#include "../../game/model/session.h"
#include "sessiontreemodel.h"
#include <list>
#include <gtkmm.h>
#include <libglademm/xml.h>

namespace client {
	namespace ui {
		namespace controllers {
			/**
			 * Controlador para la ventana principal del Juego.
			 * @author Gabriel Raineri
			 */
			class InitWindowController {
				private:
					client::game::model::GameClient* gameClient;
					Glib::RefPtr<Gnome::Glade::Xml> refXml;
					Gtk::Window* initWindow;
					Gtk::Label* messageLabel;
					Gtk::Frame* connectionFrame;
					Gtk::Entry* ipEntry;
					Gtk::Entry* nickEntry;				
					Gtk::TreeView* sessionTree;
					Gtk::Button* refreshButton;
					Gtk::Button* singleSessionButton;
					Gtk::Button* multiSessionButton;					
					Gtk::Button* joinSessionButton;
					SessionTreeModel sessionTreeModel; 
					Glib::RefPtr<Gtk::ListStore> refTreeModel;
					 
					// Acciones con Widgets
					void initWidgets();
					void populateTreeview(
							std::list<client::game::model::Session*>* sessionList);
					void enableActionButtons(bool enable);									
					
					// Bindings					
					void bindSignals();
					void bindConnectButton();
					void bindRefreshButton();
					void bindSingleSessionButton();
					void bindMultiSessionButton();
					void bindJoinSessionButton();
					void bindExitButton();
					void bindDefault();
					
					// Events
					void onConnectButtonClicked();
					void onRefreshButtonClicked();
					void onSingleSessionButtonClicked();
					void onMultiSessionButtonClicked();
					void onJoinSessionButtonClicked();
					void onExitButtonClicked();
					
					// Timers
					sigc::slot<bool> loginSlot;
					sigc::slot<bool> sessionsSlot;
					sigc::slot<bool> joinSlot;
					sigc::slot<bool> opponentSlot;
					sigc::connection timeoutTimer;
					void initSlots();
					
					bool checkForLoginResponse();
					bool checkForSessionsResponse();
					bool checkForJoinResponse();
					bool checkForOpponentResponse();
					
					void retrieveAvailableSessions();
					
					void setPlayGame(const std::string& textToShow);
					
					bool playGame;
					bool multiplayer;
					
				public:
					InitWindowController(client::game::model::GameClient* gameClient);
					~InitWindowController();
					
					InitResponse show();
			};
		}
	}
}

#endif /*CLIENTE_GAME_UI_INITWINDOWCONTROLLER_H_*/
