#include "messagesender.h"
#include "sockets/exceptions/tcpsocketexception.h"
#include "logger/tri_logger.h"

using namespace server::game::client;
using namespace common::sockets;
using namespace common::sockets::exceptions;
using namespace common::protocol;
using namespace common::threads::locks;
using namespace std;

MessageSender::MessageSender(
		MessagePool* messagePool, common::sockets::TcpSocket* clientSocket) :
	
	messagePool(messagePool), 
	clientSocket(clientSocket),
	conditionalWait(new ConditionalWait()) {
	
	this->messagePool->setConditionalWait(this->conditionalWait);
}

MessageSender::~MessageSender() {
	delete this->conditionalWait;
}

void MessageSender::clearMessages(vector<Data*>* messages) {
	vector<Data*>::const_iterator i;
	for (i = messages->begin(); i != messages->end(); ++i) {
		delete *i;
	}
	messages->clear();
	delete messages;
}

void MessageSender::sendMessages(vector<Data*>* messages) {
	vector<Data*>::const_iterator i;
	for (i = messages->begin(); i != messages->end(); ++i) {
		this->protocolSender.sendToSocket(*(this->clientSocket), *(*i));		
	}
}

void MessageSender::stop() {
	Thread::stop();
	this->messagePool->releaseConditionalWait();
}

void MessageSender::run() {
	while (!this->isStopped()) {		
		this->conditionalWait->wait();
		vector<Data*>* messages = this->messagePool->getAllMessages();
		if (messages) {
			try {
				this->sendMessages(messages);
			} catch (const TcpSocketException& e) {
				this->stop();
				TRI_LOG_STR("MessageSender Detenido.");
			}
			this->clearMessages(messages);
		}
	}
}
