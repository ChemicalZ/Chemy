#pragma once

#include "Chemy\Core.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

namespace Chemy {

	class CHEMY_API AssetManager {
	public:
		sf::Texture LoadTexture(std::string, std::string);
		sf::SoundBuffer LoadSound(std::string, std::string);
		sf::Font LoadFont(std::string, std::string);

	private:
		// Variable to store data
		std::unordered_map<std::string, sf::Texture> _textures;
		std::unordered_map<std::string, sf::SoundBuffer> _sounds;
		std::unordered_map<std::string, sf::Font> _fonts;
	};

}