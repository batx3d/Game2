#include "PhysicalFunction.h"

#include <math.h>
#include <iostream>

float Engine::PhysicalFunction::getSpeed(float oldSpeed, float acceleration, float time) {
	return oldSpeed + acceleration * time;
}

float Engine::PhysicalFunction::getMoving(float speed, float time) {
	return speed * time;
}