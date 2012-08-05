#include "conditionalwait.h"

using namespace common::threads::locks;

ConditionalWait::ConditionalWait() :
		cond(new pthread_cond_t),
		counter(0) {
	
	pthread_cond_init(cond, NULL);			
}

ConditionalWait::~ConditionalWait() {
	pthread_cond_destroy(cond);
	delete this->cond;	
}

void ConditionalWait::wait() {
	if (this->counter >= 0) {
		this->mutex.lock();
		this->counter++;
		pthread_cond_wait(cond, mutex.getMutex());
		this->mutex.unlock();
	} else {
		this->counter++;
	}
}

void ConditionalWait::broadcast() {		
	if (this->counter > 0) {
		this->mutex.lock();
		this->counter = 0;
		pthread_cond_broadcast(cond);
		this->mutex.unlock();
	} else {
		this->counter = -1;
	}
}

void ConditionalWait::signal() {
	if (this->counter > 0) {
		this->mutex.lock();
		this->counter--;
		pthread_cond_signal(cond);
		this->mutex.unlock();
	} else {
		this->counter = -1;
	}
}
