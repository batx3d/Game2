#include "Textures.h"

void Engine::Textures::addTexture(int number, sf::Texture* texture) {
	textures[number] = texture;
}

void Engine::Textures::addTexture(int number, sf::String path) {
	sf::Texture* texture = new sf::Texture();

	if (texture->loadFromFile(path))
		addTexture(number, texture);
}

sf::Texture* Engine::Textures::getTexture(int number) {
	return textures[number];
}

Engine::Textures::~Textures() {
	for (std::map<int, sf::Texture*>::iterator it = textures.begin(); it != textures.end(); it++)
		delete it->second;
}