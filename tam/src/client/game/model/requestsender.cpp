#include "requestsender.h"
#include "outcomingrequestqueue.h"
#include "../commands/command.h"
#include "sockets/exceptions/tcpsocketexception.h"
#include "threads/locks/conditionalwait.h"
#include "logger/tri_logger.h"
#include "utils/collections.h"

using namespace client::game::model;
using namespace client::game::commands;
using namespace common::protocol;
using namespace common::sockets;
using namespace common::sockets::exceptions;
using namespace common::threads::locks;
using namespace std;

RequestSender::RequestSender(TcpSocket* tcpSocket) :
	tcpSocket(tcpSocket) {

}

RequestSender::~RequestSender() {

}

void RequestSender::clearRequests(vector<const Command*>* requests) {
	common::utils::DeleteAndClearElements(*requests);
	delete requests;
}

void RequestSender::executeRequests(vector<const Command*>* requests) {
	vector<const Command*>::const_iterator i;
	for (i = requests->begin(); i != requests->end(); ++i) {
		string request = (*i)->buildRequest();
		this->protocolSender.sendToSocket(*(this->tcpSocket), request);
		TRI_LOG_STR("RequestSender: Request enviado --> " + request);
	}
}

void RequestSender::stop() {
	Thread::stop();
	OutcomingRequestQueue::getInstance().releaseConditionalWait();
}

void RequestSender::run() {
	OutcomingRequestQueue& requestQueue = OutcomingRequestQueue::getInstance();
	ConditionalWait* conditionalWait = requestQueue.getConditionalWait();
	while (!this->isStopped()) {
		conditionalWait->wait();
		vector<const Command*>* requests = requestQueue.getAllQueuedRequests();
		if (requests) {
			try {
				this->executeRequests(requests);
			} catch (const TcpSocketException& e) {
				this->stop();
				TRI_LOG_STR("RequestSender Detenido.");
			}
			this->clearRequests(requests);
		}
	}
}
