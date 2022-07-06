#pragma once

#include <SFML/Graphics.hpp>
#include <thread>

#include "GameScene.h"

namespace Engine
{
	class GameScene;

	class Window
	{
	private:
		sf::RenderWindow* window;
		GameScene* scene = NULL;
		std::thread th;

		const int SYSTEM_DELAY = 15;

		bool visible;
		bool isClose;

	public:
		Window(int width, int height, sf::String title = "", bool resizable = true);
		~Window();

		Vector2i getMousePosition();

		void setGameScene(GameScene* scene);

		sf::View getView();
		void setView(sf::View view);

		Vector2i getSize();

		void setVisible(bool visible);
		bool getVisible();

		void launch();

	private:
		void lifeCycle();
		void draw();
	};
}