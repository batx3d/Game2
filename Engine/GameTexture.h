#pragma once

#include <SFML/Graphics.hpp>

namespace Engine
{
	class GameTexture
	{
	private:
		sf::Texture* texture;

	public:
		GameTexture(sf::String path);
		~GameTexture();

		void setTexture(sf::String path);
		sf::Texture* getTexture();
	};
}