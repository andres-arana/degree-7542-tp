#include "toolbarexpander.h"
#include "utils/stringutils.h"

#define PRICE_DESCRIPTION "Precio:"
#define NUMBER_DESCRIPTION "Cantidad:"
#define AVAILABLE_DESCRIPTION "Disponible:"

using namespace client::ui::widgets;
using namespace common::utils;
using namespace game::logic::properties;
using namespace std;

ToolbarExpander::ToolbarExpander() : 	
	priceDescription(PRICE_DESCRIPTION), 
	numberDescription(NUMBER_DESCRIPTION), 
	availableDescription(AVAILABLE_DESCRIPTION),
	properties(NULL) {
	
	this->firstColumn.add(priceDescription);
	this->firstColumn.add(numberDescription);
	this->firstColumn.add(availableDescription);
	
	this->secondColumn.add(this->priceLabel);
	this->secondColumn.add(this->numberLabel);
	this->secondColumn.add(this->availableLabel);
	
	this->columns.add(this->firstColumn);
	this->columns.add(this->secondColumn);
	this->add(this->columns);
	this->set_expanded();
}

void ToolbarExpander::setPrice(const string& price) {
	this->priceLabel.set_text(price);
}

void ToolbarExpander::setNumber(const string& number) {
	this->numberLabel.set_text(number);
}

void ToolbarExpander::setAvailable(const string& available) {
	this->availableLabel.set_text(available);
}

void ToolbarExpander::setElementProperties(ElementProperties* properties) {
	this->properties = properties;
}

void ToolbarExpander::updateValues() {
	if (!this->properties) return;
	
	string price 
			= StringUtils::numberToString<int>(this->properties->getPrice());
	string number
			= StringUtils::numberToString<int>(this->properties->getNumber());
	string available 
			= StringUtils::numberToString<int>(this->properties->getAvailableNumber());
			
	this->setPrice(price);
	this->setNumber(number);
	this->setAvailable(available);
}

void ToolbarExpander::moveToContainer(Gtk::Container& container) {
	Gtk::Container* parentContainer = this->get_parent();
	if (parentContainer) {
		parentContainer->remove(*this);
	}
	container.add(*this);
	this->set_expanded();
	container.show_all();
}
