#include "Vector2f.h"

#include <math.h>

Engine::Vector2f::Vector2f(float x, float y) {
	setX(x);
	setY(y);
}

void Engine::Vector2f::setX(float x) {
	this->x = x;
}

float Engine::Vector2f::getX() {
	return x;
}

void Engine::Vector2f::setY(float y) {
	this->y = y;
}

float Engine::Vector2f::getY() {
	return y;
}

float Engine::Vector2f::getLength() {
	return sqrt(pow(x, 2) + pow(y, 2));
}

float Engine::Vector2f::getDistance(Engine::Vector2f vector) {
	return sqrt(pow((vector.getX() - getX()), 2) + pow((vector.getY() - getY()), 2));
}