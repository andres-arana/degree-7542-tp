#include "thread.h"
#include <iostream>
#include "locks/sharedreadlock.h"
#include "locks/exclusivewritelock.h"

using namespace common::threads;
using namespace common::threads::locks;

Thread::Thread() : rwLock(new ReadWriteLock), stopped(false) {
	
}

Thread::~Thread() {
	this->stopped = true;
	delete this->rwLock;
}

void* Thread::static_run(void* argThis) {
	Thread* pThis = static_cast<Thread*> (argThis);
	pThis->run(); 
	return NULL;   
}

void Thread::start() {
	this->stopped = false; 
	pthread_create(&tid, NULL, &Thread::static_run, this);
}

void Thread::stop() {
	ExclusiveWriteLock ewl(this->getLock());
	this->stopped = true;
} 

void Thread::join() {
	Thread::join(this->tid);
}

void Thread::join(pthread_t threadId) {
	pthread_join(threadId, NULL);
}

void Thread::sleep(int ms) {
	usleep(ms);
}

void Thread::cancel() {
	pthread_cancel(this->tid);
}

pthread_t Thread::getCurrentThread() {
  return pthread_self();
}

bool Thread::isStopped() const {
	SharedReadLock srl(this->getLock());
	return this->stopped;
}

pthread_t Thread::getTid() const {
	return this->tid;
}

ReadWriteLock& Thread::getLock() const {
	return *(this->rwLock);
}

void Thread::run() {

}
