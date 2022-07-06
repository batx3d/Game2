#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "GameScene.h"
#include "Textures.h"
#include "GameTexture.h"
#include "Vector2f.h"

namespace Engine
{
	class GameScene;

	class GameObject
	{
	private:
		bool statusDelete = false;

	protected:
		GameScene* scene;
		Textures* textures;
		sf::Texture* texture;

		std::string id;

		Vector2f speed = { 0, 0 };
		Vector2f positions;
		Vector2i size;

		void setStatusDelete(bool status);

	public:
		GameObject(GameScene* scene, std::string id, Textures* textures, Vector2i size);
		~GameObject();

		bool isDelete();
		std::string getId();

		void setTextures(Textures* textures);
		void setTexture(int number);

		void setSize(Vector2i size);
		Vector2i getSize();

		void setPositions(Vector2f position);
		Vector2f getPositions();

		Vector2f getCenter();

		void setSpeed(Vector2f speed);
		Vector2f getSpeed();

		GameScene* getScene();

		virtual void run(int time) = 0;

		void draw(sf::RenderWindow* window);
	};
}