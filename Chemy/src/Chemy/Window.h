#pragma once
#include "SFML/Graphics.hpp"
#include "EventSystem/EventSystem.h"

namespace Chemy {

	const int DEFAULT_HEIGHT = 1280;
	const int DEFAULT_WIDTH = 720;

	struct WindowProps {
		std::string _title;
		int _height, _width;
		WindowProps(std::string title= "Default Window", int height = DEFAULT_HEIGHT, int width= DEFAULT_WIDTH) : 
			_title(title), _height(height), _width(width) {}
	};
	class CHEMY_API Window {
	public:
		//Initializes window with default properties
		Window(WindowProps);
		//Returns copy of the actual window
		static Window* Create(const WindowProps& props = WindowProps());
		//Initializes window 
		void Init(WindowProps);
		//Update loop
		//TODO: replace with onEvent()
		void Update();
		//Draw Function
		void Draw(const sf::Drawable&, int);
		//return height
		int GetHeight();
		//return width
		int GetWidth();
		//Render the Screen
		void Render();
	private:
		std::multimap<int, const sf::Drawable&> _drawqueue;
		struct WindowData {
			std::string _title;
			int _width, _height;
			std::unique_ptr<sf::RenderWindow> _window;
		};
		WindowData _data;

	};
}