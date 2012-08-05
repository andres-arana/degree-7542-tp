#include "session.h"

using namespace client::game::model;
using namespace std;

Session::Session(const string& id, const string& name) :
	id(id),
	name(name) {
		
}

const string& Session::getId() const {
	return this->id;
}

const string& Session::getName() const {
	return this->name;
}
