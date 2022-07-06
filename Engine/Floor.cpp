
#include "Floor.h"

Engine::Floor::Floor(Vector2i count, Vector2i size, GameTexture* texture) : count(count), size(size) {
	this->texture = texture;
}

Engine::Floor::~Floor() {
	delete texture;
}

void Engine::Floor::setTexture(GameTexture* texture) {
	delete this->texture;
	this->texture = texture;
}

void Engine::Floor::draw(sf::RenderWindow* window)
{
	for (int i = 0; i < count.getX(); i++)
		for (int j = 0; j < count.getY(); j++) {
			texture->getTexture();
			sf::Sprite sprite(*texture->getTexture());
			sprite.setPosition(i * size.getX(), j * size.getY());
			window->draw(sprite);
		}
}