#include "messagepool.h"
#include "threads/locks/lock.h"

using namespace server::game::client;
using namespace common::threads::locks;
using namespace common::sockets;
using namespace std;

MessagePool::MessagePool() : 
	condWait(NULL) {
	
}

MessagePool::~MessagePool() {

}

void MessagePool::addMessage(const string& message) {
	Lock lock(this->mutex);
	Data* data = new Data(message);
	this->messagePool.push_back(data);
	this->condWait->broadcast();
}

void MessagePool::addMessage(Data* message) {
	Lock lock(this->mutex);
	this->messagePool.push_back(message);
	this->condWait->broadcast();
}

vector<Data*>* MessagePool::getAllMessages() {
	Lock lock(this->mutex);
	if (this->messagePool.empty()) return NULL;
	
	vector<Data*>* messages 
			= new vector<Data*>(this->messagePool.begin(), this->messagePool.end());
	this->messagePool.clear();
	return messages;
}

void MessagePool::setConditionalWait(ConditionalWait* condWait) {
	this->condWait = condWait;
}

void MessagePool::releaseConditionalWait() {
	Lock lock(this->mutex);
	this->condWait->broadcast();
}

