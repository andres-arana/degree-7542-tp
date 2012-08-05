#include "exclusivewritelock.h"

using namespace common::threads::locks;

ExclusiveWriteLock::ExclusiveWriteLock(ReadWriteLock& rwLock) : rwLock(rwLock) {
	rwLock.exclusiveWriteLock();
}

ExclusiveWriteLock::~ExclusiveWriteLock() {
	rwLock.unlock();
}
