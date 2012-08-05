#include "lock.h"

using namespace common::threads::locks;

Lock::Lock(Mutex& mutex) : mutex(mutex) {
	mutex.lock();
}

Lock::~Lock() {
	mutex.unlock();
}
