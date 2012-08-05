#include "incomingmessagequeue.h"
#include "threads/locks/lock.h"
#include "logger/tri_logger.h"
#include "utils/collections.h"

using namespace client::game::model;
using namespace common::threads::locks;
using namespace std;

IncomingMessageQueue::IncomingMessageQueue() {

}

IncomingMessageQueue::~IncomingMessageQueue() {
  common::utils::DeleteAndClearElements(this->messages);
}

IncomingMessageQueue& IncomingMessageQueue::getInstance() {
  static IncomingMessageQueue instance;
  return instance;
}

void IncomingMessageQueue::addMessageToQueue(const Message* message) {
  Lock lock(this->mutex);
  this->messages.push_back(message);
}

vector<const Message*>* IncomingMessageQueue::getAllQueuedMessages() {
  Lock lock(this->mutex);
  vector<const Message*>* queuedMessages = new vector<const Message*>(
      this->messages.begin(), this->messages.end());
  this->messages.clear();
  return queuedMessages;
}
