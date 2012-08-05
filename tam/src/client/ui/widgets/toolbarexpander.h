#ifndef CLIENT_GAME_UI_WIDGETS_TOOLBAREXPANDER_H_
#define CLIENT_GAME_UI_WIDGETS_TOOLBAREXPANDER_H_

#include <gtkmm.h>
#include <string>
#include "logic/properties/elementproperties.h"

namespace client {
	namespace ui {
		namespace widgets {
			class ToolbarExpander : public Gtk::Expander {
				private:
					Gtk::Label priceDescription;
					Gtk::Label numberDescription;
					Gtk::Label availableDescription;
					Gtk::Label priceLabel;
					Gtk::Label numberLabel;
					Gtk::Label availableLabel;
					Gtk::HBox columns;
					Gtk::VBox firstColumn;
					Gtk::VBox secondColumn;					
					
					::game::logic::properties::ElementProperties* properties;
					
					void setPrice(const std::string& price);
					void setNumber(const std::string& number);
					void setAvailable(const std::string& avaiable);
					
				public:
					ToolbarExpander();
					
					void setElementProperties(
							::game::logic::properties::ElementProperties* properties);
							
					void updateValues();
					
					void moveToContainer(Gtk::Container& container);				
			};		
		}
	}
}

#endif /*CLIENT_GAME_UI_WIDGETS_TOOLBAREXPANDER_H_*/
