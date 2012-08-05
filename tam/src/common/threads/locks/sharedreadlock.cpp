#include "sharedreadlock.h"

using namespace common::threads::locks;

SharedReadLock::SharedReadLock(ReadWriteLock& rwLock) : rwLock(rwLock) {
	rwLock.sharedReadLock();
}

SharedReadLock::~SharedReadLock() {
	rwLock.unlock();
}
