#include "stageproperties.h"

using namespace game::logic::properties;

StageProperties::StageProperties() :
	A(0),
	B(0),
	C(0),
	D(0),
	timeToSolve(0) {

}

StageProperties::StageProperties(int A, int B, int C, int D, int timeToSolve) :
	A(A),
	B(B),
	C(C),
	D(D),
	timeToSolve(timeToSolve) {

}

int StageProperties::getA() const {
	return this->A;
}

void StageProperties::setA(int A) {
	this->A = A;
}

int StageProperties::getB() const {
	return this->B;
}

void StageProperties::setB(int B) {
	this->B = B;
}

int StageProperties::getC() const {
	return this->C;
}

void StageProperties::setC(int C) {
	this->C = C;
}

int StageProperties::getD() const {
	return this->D;
}

void StageProperties::setD(int D) {
	this->D = D;
}

int StageProperties::getTimeToSolve() const {
	return this->timeToSolve;
}

void StageProperties::setTimeToSolve(int timeToSolve) {
	this->timeToSolve = timeToSolve;
}

int StageProperties::getGravity() const {
	return this->gravity;
}

void StageProperties::setGravity(int gravity) {
	this->gravity = gravity;
}

