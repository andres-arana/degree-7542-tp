#include "readwritelock.h"

using namespace common::threads::locks;

ReadWriteLock::ReadWriteLock() {
	pthread_rwlock_init(&lock, NULL);
}

ReadWriteLock::~ReadWriteLock() {
	this->unlock();
	pthread_rwlock_destroy(&lock);
}

void ReadWriteLock::sharedReadLock() {
	pthread_rwlock_rdlock(&lock);
}

void ReadWriteLock::exclusiveWriteLock() {
	pthread_rwlock_wrlock(&lock);
}

void ReadWriteLock::unlock() {
	pthread_rwlock_unlock(&lock);  
}
