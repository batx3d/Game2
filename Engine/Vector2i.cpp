#include "Vector2i.h"

#include <math.h>

Engine::Vector2i::Vector2i(int x, int y) {
	setX(x);
	setY(y);
}

void Engine::Vector2i::setX(int x) {
	this->x = x;
}

int Engine::Vector2i::getX() {
	return x;
}

void Engine::Vector2i::setY(int y) {
	this->y = y;
}

int Engine::Vector2i::getY() {
	return y;
}

int Engine::Vector2i::getLength() {
	return sqrt(pow(x, 2) + pow(y, 2));
}

int Engine::Vector2i::getDistance(Engine::Vector2i vector) {
	return sqrt(pow((vector.getX() - getX()), 2) + pow((vector.getY() - getY()), 2));
}