
#include "GameTexture.h"

Engine::GameTexture::GameTexture(sf::String path) {
	texture = new sf::Texture();
	setTexture(path);
}

Engine::GameTexture::~GameTexture() {
	delete texture;
}

void Engine::GameTexture::setTexture(sf::String path) {
	texture->loadFromFile(path);
}

sf::Texture* Engine::GameTexture::getTexture() {
	return texture;
}