#include "math.h"

using namespace common::utils;

const double Math::PI = 3.14159265358979323846;

Math::Math() {

}

Math::~Math() {

}

char Math::countDigits(int number) {
	int digits = 1;
  int result = number;
  while ((result /= 10) > 0) {
  	digits++;
  }
  return digits;
}
