#include "OneScene.h"
#include "Player.h"

#include <math.h>

#include <iostream>

OneScene::OneScene(Window* window) : GameScene({ 45, 29 }, { 40, 40 }, NULL, window) {
	Textures* texturesLevels = new Textures();
	texturesLevels->addTexture(1, "Textures/Levels/One/Walls/Wall_1.png");
	setTextures(texturesLevels);
	setFloor(new Floor({ 22, 14 }, { 128, 128 }, new GameTexture("Textures/Levels/One/Floors/Floor.png")));
	/*setWalls(0, "0000100000");
	setWalls(1, "0000100000");
	setWalls(2, "0000100000");
	setWalls(5, "1111100000");*/
	setWall({ 12, 8 }, 1);
	setWall({ 22, 8 }, 1);
	setWall({ 32, 8 }, 1);

	setWall({ 12, 14 }, 1);
	setWall({ 22, 14 }, 1);
	setWall({ 32, 14 }, 1);

	setWall({ 12, 20 }, 1);
	setWall({ 22, 20 }, 1);
	setWall({ 32, 20 }, 1);

	addObject(new Player(this, { 25, 32 }));
}

void OneScene::run(int time)
{
	GameScene::run(time);

	for (GameObject* obj : gameObjects) {
		if (obj->getId() == "Player")
		{
			sf::View view = window->getView();

			Vector2i sizeWindow = window->getSize();
			Vector2f centerPlayer = obj->getCenter();
			Vector2i sizeScene = { count.getX() * size.getX(), count.getY() * size.getY() };
			Vector2i centerWindow = { sizeWindow.getX() / 2, sizeWindow.getY() / 2 };

			if (centerPlayer.getX() > centerWindow.getX() && centerPlayer.getX() < sizeScene.getX() - centerWindow.getX())
				view.setCenter({ (float)(centerPlayer.getX()), view.getCenter().y });
			
			if (centerPlayer.getY() > centerWindow.getY() && centerPlayer.getY() < sizeScene.getY() - centerWindow.getY())
				view.setCenter({ view.getCenter().x, (float)(centerPlayer.getY()) });

			window->setView(view);
		}
	}
}