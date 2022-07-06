#include "FirstLevel.h"

FirstLevel::FirstLevel(Window* window) {
	Textures* texturesLevels = new Textures();
	texturesLevels->addTexture(1, "Textures/Levels/One/Walls/Wall_1.png");
	scene = new GameScene({ 44, 28 }, { 40, 40 }, texturesLevels, window);
	scene->setFloor(new Floor({ 22, 14 }, { 128, 128 }, new GameTexture("Textures/Levels/One/Floors/Floor.png")));
	scene->setWalls(0, "0000100000");
	scene->setWalls(1, "0000100000");
	scene->setWalls(2, "0000100000");
	scene->setWalls(5, "1111100000");

	scene->addObject(new Player(scene, { 25, 32 }));
}

GameScene* FirstLevel::getGameScene() {
	return scene;
}