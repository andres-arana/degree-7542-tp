#include "outcomingrequestqueue.h"
#include "../commands/command.h"
#include "threads/locks/lock.h"
#include "utils/collections.h"

using namespace client::game::model;
using namespace client::game::commands;
using namespace common::threads::locks;
using namespace std;

OutcomingRequestQueue::OutcomingRequestQueue() {

}

OutcomingRequestQueue::~OutcomingRequestQueue() {
  common::utils::DeleteAndClearElements(this->requests);
}

OutcomingRequestQueue& OutcomingRequestQueue::getInstance() {
  static OutcomingRequestQueue instance;
  return instance;
}

void OutcomingRequestQueue::addRequest(const Command* command) {
  Lock lock(this->mutex);
  this->requests.push_back(command);
  this->conditionalWait.broadcast();
}

vector<const Command*>* OutcomingRequestQueue::getAllQueuedRequests() {
  Lock lock(this->mutex);
  if (this->requests.empty()) return NULL;

  vector<const Command*>* queuedRequests = new vector<const Command*>(
      this->requests.begin(), this->requests.end());
  this->requests.clear();
  return queuedRequests;
}

ConditionalWait* OutcomingRequestQueue::getConditionalWait() {
	return &(this->conditionalWait);
}

void OutcomingRequestQueue::releaseConditionalWait() {
	Lock lock(this->mutex);
	this->conditionalWait.broadcast();
}
