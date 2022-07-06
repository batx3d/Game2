#include "GameObject.h"

Engine::GameObject::GameObject(GameScene* scene, std::string id, Textures* textures, Vector2i size) :
	scene(scene), textures(textures), size(size), id(id) {
	positions = { 0, 0 };
}

Engine::GameObject::~GameObject() {
	delete textures;
}

void Engine::GameObject::setStatusDelete(bool status) {
	statusDelete = status;
}

bool Engine::GameObject::isDelete() {
	return statusDelete;
}

std::string Engine::GameObject::getId() {
	return id;
}

void Engine::GameObject::setTextures(Textures* textures) {
	delete this->textures;
	this->textures = textures;
}

void Engine::GameObject::setTexture(int number) {
	this->texture = textures->getTexture(number);
}

void Engine::GameObject::draw(sf::RenderWindow* window) {
	sf::Sprite sp = sf::Sprite(*texture);
	sp.setPosition(getPositions().getX(), getPositions().getY());
	window->draw(sp);
}

void Engine::GameObject::setSize(Vector2i size) {
	this->size = size;
}

Engine::Vector2i Engine::GameObject::getSize() {
	return size;
}

void Engine::GameObject::setPositions(Engine::Vector2f position) {
	this->positions = position;
}

Engine::Vector2f Engine::GameObject::getPositions() {
	return positions;
}

Engine::Vector2f Engine::GameObject::getCenter() {
	return { positions.getX() + (float)size.getX() / 2, positions.getY() + (float)size.getY() / 2 };
}

void Engine::GameObject::setSpeed(Engine::Vector2f speed) {
	this->speed = speed;
}

Engine::Vector2f Engine::GameObject::getSpeed() {
	return speed;
}

Engine::GameScene* Engine::GameObject::getScene() {
	return scene;
}