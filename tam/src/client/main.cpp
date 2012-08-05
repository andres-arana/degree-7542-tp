#include <gtkmm.h>
#include "ui/controllers/initwindowcontroller.h"
#include "ui/controllers/gamewindowcontroller.h"
#include "ui/controllers/initresponse.h"
#include "game/model/gameclient.h"

using namespace client::game::model;
using namespace client::ui::controllers;

int main(int argc, char* argv[]) {
  Gtk::Main kit(argc, argv);
  GameClient* gameClient = new GameClient();
  InitWindowController initWindowController(gameClient); 
  InitResponse initResponse = initWindowController.show();
  if (!initResponse.getExited()) {
  	GameWindowController gameWindowController(
  			gameClient, initResponse.getMultiplayerSession());
  	gameWindowController.show();
  }
  delete gameClient;
  return 0;
}
