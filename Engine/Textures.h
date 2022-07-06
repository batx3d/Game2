#pragma once

#include <SFML/Graphics.hpp>
#include <map>

//using namespace sf;

namespace Engine
{
	class Textures
	{
	private:
		std::map<int, sf::Texture*> textures;

	public:
		~Textures();

		void addTexture(int number, sf::Texture* texture);
		void addTexture(int number, sf::String path);
		sf::Texture* getTexture(int number);
	};
}