#pragma once
#include "czpch.h"

#include "AssetManager.h"

namespace Chemy {

	sf::Texture AssetManager::LoadTexture(std::string name, std::string path) {
		//Iterator to search database
		auto it = _textures.find(name);

		//Check to see if texture already exists
		if (it == _textures.end()) {
			sf::Texture temp;
			//Load the texture from the specified path
			if (!temp.loadFromFile(path)) {
				//Path to texture not found
				CZ_CORE_WARN("Path to Texture \"{}\" not found: {}", name, path);
			}
			//Texture has been added
			CZ_CORE_INFO("Texture \"{}\" added: {}", name, path);
			_textures.emplace(name, temp);
			//Return copy of stored texture

			return temp;
		}
		//Texture Exists

		else {
			//Return Texture
			return it->second;
		}
	}

	
	//Load texture
	sf::Texture AssetManager::LoadTexture(std::string name) {
		//Iterator to search database
		auto it = _textures.find(name);
		//Check to see if texture already exists
		if (it == _textures.end()) {
			sf::Texture temp;
			CZ_CORE_ERROR("Attempted to load unknown texture {}.", name);
			return temp;
		}
		//Texture Exists

		else {
			//Return Texture
			return it->second;
		}
	}
	
	sf::SoundBuffer AssetManager::LoadSound(std::string name, std::string path) {
		//Iterator to search database
		auto it = _sounds.find(name);

		//Check to see if sound already exists
		if (it == _sounds.end()) {
			sf::SoundBuffer temp;
			//Load the sound from the specified path
			if (!temp.loadFromFile(path)) {
				//Path to sound not found
				CZ_CORE_WARN("Path to Audio File \"{}\" not found: {}", name, path);
			}
			//Sound has been added
			CZ_CORE_INFO("Audio file \"{}\" added: {}", name, path);
			_sounds.emplace(name, temp);
			//Return copy of stored sound
			return temp;
		}
		//sound Exists

		else {
			//Return sound
			return it->second;
		}
	}

	sf::SoundBuffer AssetManager::Loadsound(std::string name){
	//Iterator to search database
		auto it = _sounds.find(name);

		//Check to see if sound already exists
		if (it == _sounds.end()) {
			sf::SoundBuffer temp;
			CZ_CORE_ERROR("Attempted to load unknown sound {}", name);
			return temp;
		}
		//sound Exists

		else {
			//Return sound
			return it->second;
		}
	}

	//LoadFont(name,path)
	sf::Font AssetManager::LoadFont(std::string name, std::string path) {
		//Iterator to search database
		auto it = _fonts.find(name);

		//Check to see if font already exists
		if (it == _fonts.end()) {
			sf::Font temp;
			//Load the font from the specified path
			if (!temp.loadFromFile(path)) {
				//Path to font not found
				CZ_CORE_WARN("Path to Font File \"{}\" not found: {}", name, path);
			}
			//Sound has been added
			CZ_CORE_INFO("Font \"{}\" added: {}", name, path);
			_fonts.emplace(name, temp);
			//Return copy of stored font
			return temp;
		}
		//sound Exists

		else {
			//Return sound
			return it->second;
		}
	}
	//LoadFont(name)
	sf::Font AssetManager::LoadFont(std::string name) {
		//Iterator to search database
		auto it = _fonts.find(name);

		//Check to see if font already exists
		if (it == _fonts.end()) {
			sf::Font temp;
			CZ_CORE_ERROR("Attempted to load unknown Font {}", name);
			return temp;
		}
		//sound Exists

		else {
			//Return sound
			CZ_CORE_INFO("{} Font requested", name);
			return it->second;
		}
	}

}