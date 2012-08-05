#include "message.h"

#define REC_SEPARATOR '\30' // Record Separator

using namespace client::game::model;
using namespace std;

Message::Message(const string& from, const string& text) :
	from(from), 
	text(text) {
  
}

const string& Message::getFrom() const {
  return this->from;
}

const string& Message::getText() const {
  return this->text;
}

const Message* Message::createMessage(const string& messageStr) {
  size_t startOfMessage = 0;
  string from = "";
  string text = "";
  if (messageStr.at(0) == REC_SEPARATOR) {
    startOfMessage = messageStr.find(REC_SEPARATOR, 1);
    from.append(messageStr.substr(1, startOfMessage - 1));
    startOfMessage++;
  }
  text.append(messageStr.substr(startOfMessage));
  return new Message(from, text);
}
