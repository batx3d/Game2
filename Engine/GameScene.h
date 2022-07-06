#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

#include <iostream>

#include "Textures.h"
#include "Floor.h"
#include "GameObject.h"
#include "Vector2i.h"
#include "Vector2f.h"
#include "Window.h"

#include <algorithm>

namespace Engine
{
	class GameObject;
	class Window;

	class GameScene
	{
	protected:
		int** scene;

		Window* window;

		Vector2i count;
		Vector2i size;

		Textures* textures;
		Floor* floor = NULL;
		std::vector<GameObject*> gameObjects;
		std::vector<GameObject*> bufferGameObjects;

	private:
		void addObjectsFromBuffer();

	public:
		GameScene(Vector2i count, Vector2i size, Textures* textures, Window* window);
		~GameScene();

		Window* getWindow();

		void setFloor(Floor* floor);
		void setTextures(Textures* textures);

		void draw(sf::RenderWindow* window);
		virtual void run(int time) = 0;

		void setView(sf::View view);

		Vector2i getCount();
		Vector2i getSize();

		void addObject(GameObject* object);
		void deleteObject();

		void fillScene(int value);
		void setWalls(int numberRow, std::string row);
		void setWall(Vector2i positions, int value);

		Vector2i getCellPosition(Vector2f positions);
		bool isWall(Vector2f positions, Vector2i size);

		std::vector<GameObject*> getObjectsCollisions(Engine::GameObject* object);
	};
}