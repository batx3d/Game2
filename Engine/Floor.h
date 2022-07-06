#pragma once

#include <SFML/Graphics.hpp>

#include "GameTexture.h"
#include "Vector2i.h"

namespace Engine
{
	class Floor
	{
	private:
		GameTexture* texture;
		Vector2i count;
		Vector2i size;

	public:
		Floor(Vector2i count, Vector2i size, GameTexture* texture);
		~Floor();

		void setTexture(GameTexture* texture);
		void draw(sf::RenderWindow* window);
	};
}