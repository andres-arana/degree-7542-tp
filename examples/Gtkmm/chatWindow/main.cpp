#include "clientview.h"
#include <gtkmm.h>

int main(int argc, char* argv[]) {
  Gtk::Main kit(argc, argv);  
  ClientView view;
  Gtk::Main::run(view);
  return 0;
}
