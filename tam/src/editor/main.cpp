#include "presentation/stageeditorguiglade.h"

using editor::presentation::StageEditorGuiGlade;


int main(int argc, char* argv[]) {
	Gtk::Main kit(argc, argv);
	StageEditorGuiGlade gui(kit);
	return 0;
}
