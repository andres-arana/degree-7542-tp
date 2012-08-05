#include "mutex.h"

using namespace common::threads::locks;

Mutex::Mutex() {
	pthread_mutex_init(&mutex, NULL);  
}

Mutex::~Mutex() {
	this->unlock();
	pthread_mutex_destroy(&mutex);
}

void Mutex::lock() {
	pthread_mutex_lock(&mutex);      
}

void Mutex::unlock() {
	pthread_mutex_unlock(&mutex);
}

pthread_mutex_t* Mutex::getMutex() {
	return &(this->mutex);
}
