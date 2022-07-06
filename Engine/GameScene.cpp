
#include "GameScene.h"

Engine::GameScene::GameScene(Vector2i count, Vector2i size, Textures* textures, Window* window) : count(count),
size(size), textures(textures), window(window)
{
	scene = new int* [count.getY()];

	for (int i = 0; i < count.getY(); i++)
		scene[i] = new int[count.getX()];

	fillScene(0);
}

Engine::GameScene::~GameScene()
{
	for (int i = 0; i < count.getY(); i++)
		delete[] scene[i];

	delete[] scene;

	delete textures;
	delete floor;
}

Engine::Window* Engine::GameScene::getWindow() {
	return window;
}

void Engine::GameScene::run(int time) {
	addObjectsFromBuffer();

	for (GameObject* obj : gameObjects)
		obj->run(time);
}

void Engine::GameScene::setView(sf::View view) {
	window->setView(view);
}

Engine::Vector2i Engine::GameScene::getCount() {
	return count;
}

Engine::Vector2i Engine::GameScene::getSize() {
	return size;
}

void Engine::GameScene::addObject(GameObject* object) {
	bufferGameObjects.push_back(object);
}

void Engine::GameScene::addObjectsFromBuffer() {
	for (GameObject* i : bufferGameObjects)
		gameObjects.push_back(i);

	bufferGameObjects.clear();
}

void Engine::GameScene::deleteObject() {
	for (int i = 0; i < gameObjects.size(); i++)
		if (gameObjects[i]->isDelete()) {
			delete gameObjects[i];
			gameObjects.erase(gameObjects.begin() + i);
		}
}

void Engine::GameScene::setFloor(Floor* floor) {
	delete this->floor;
	this->floor = floor;
}

void Engine::GameScene::fillScene(int value) {
	for (int i = 0; i < count.getY(); i++)
		for (int j = 0; j < count.getX(); j++)
			scene[i][j] = value;
}

void Engine::GameScene::setTextures(Textures* textures) {
	delete this->textures;
	this->textures = textures;
}

void Engine::GameScene::draw(sf::RenderWindow* window)
{
	if (floor != NULL)
		floor->draw(window);
	
	for (int i = 0; i < count.getY(); i++)
		for (int j = 0; j < count.getX(); j++)
			if (scene[i][j] != 0) {
				sf::Sprite sprite(*textures->getTexture(scene[i][j]));
				sprite.setPosition(j * size.getX(), i * size.getY());
				window->draw(sprite);
			}

	for (GameObject* obj : gameObjects)
		obj->draw(window);
}

void Engine::GameScene::setWalls(int numberRow, std::string row)
{
	if (numberRow >= 0 && numberRow <= count.getY())
		for (int i = 0; i < row.length(); i++) {
			if (row[i] >= '0' && row[i] <= '9') {
				char c = row[i];
				scene[numberRow][i] = atoi(&c);
			}
		}
}

void Engine::GameScene::setWall(Engine::Vector2i positions, int value) {
	scene[positions.getY()][positions.getX()] = value;
}

Engine::Vector2i Engine::GameScene::getCellPosition(Engine::Vector2f positions) {
	Vector2i cellPosition = { 0, 0 };

	if (positions.getX() < 0)
		cellPosition.setX(-1);
	else
		cellPosition.setX((int)(positions.getX() / size.getX()));
	if (positions.getY() < 0)
		cellPosition.setY(-1);
	else
		cellPosition.setY((int)(positions.getY() / size.getY()));

	return cellPosition;
}

bool Engine::GameScene::isWall(Vector2f positions, Vector2i size)
{
	int countPointsX = getSize().getX() / size.getX() + 1;
	int countPointsY = getSize().getY() / size.getY() + 1;

	for (int i = 0; i < countPointsY; i++)
		for (int j = 0; j < countPointsX; j++)
		{
			Vector2i cellPosition = getCellPosition({ positions.getX() + (size.getX() / (countPointsX - 1)) * j,
				positions.getY() + (size.getY() / (countPointsY - 1)) * i });

			if (cellPosition.getX() < 0 || cellPosition.getY() < 0 || cellPosition.getX() >= count.getX() ||
				cellPosition.getY() >= count.getY()
				|| scene[cellPosition.getY()][cellPosition.getX()] >= 1)
				return true;
		}

	return false;
}

std::vector<Engine::GameObject*> Engine::GameScene::getObjectsCollisions(Engine::GameObject* object)
{
	std::vector<Engine::GameObject*> collisions;

	for (GameObject* i : gameObjects) {
		if (i != object) {
			int left = std::max(object->getPositions().getX(), i->getPositions().getX());
			int right = std::min(object->getPositions().getX() + object->getSize().getX(),
				i->getPositions().getX() + i->getSize().getX());

			int top = std::min(object->getPositions().getY(), i->getPositions().getX());
			int bottom = std::max(object->getPositions().getY() + object->getSize().getY(),
				i->getPositions().getY() + i->getSize().getY());

			int width = right - left;
			int height = bottom - top;

			if (!(width < 0 || height < 0))
				collisions.push_back(i);
		}
	}

	return collisions;
}