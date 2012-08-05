#ifndef CLIENT_GAME_UI_CONTROLLERS_SESSIONTREEMODEL_H_
#define CLIENT_GAME_UI_CONTROLLERS_SESSIONTREEMODEL_H_

#include <gtkmm.h>
#include <string>

namespace client {
	namespace ui {
		namespace controllers {
			class SessionTreeModel : public Gtk::TreeModel::ColumnRecord {
				public:
					SessionTreeModel() {
						add(idCol); add(nameCol);
					}
					Gtk::TreeModelColumn<std::string> idCol;
					Gtk::TreeModelColumn<std::string> nameCol;
			};
		}
	}
}

#endif /*CLIENT_GAME_UI_CONTROLLERS_SESSIONTREEMODEL_H_*/
