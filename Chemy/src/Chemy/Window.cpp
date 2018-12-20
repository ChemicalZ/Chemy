#pragma once
#include "czpch.h"

#include "Window.h"


namespace Chemy {

	Window::Window(WindowProps props) {
		Init(props);
	}

	void Window::Init(WindowProps props) {
		_data._title = props._title;
		_data._height = props._height;
		_data._width = props._width;
		_data._window = std::unique_ptr<sf::Window>(new sf::Window(sf::VideoMode(_data._height, _data._width), _data._title));
		CZ_CORE_INFO("Window {} ({},{}) created", _data._title, _data._height, _data._width);
	}

	Window* Window::Create(const WindowProps& props) {
		return new Window(props);
	}

	//TODO: Poll for events like every other function
	void Window::Update() {
		// Limit the framerate to 60 frames per second (this step is optional)
		_data._window->setFramerateLimit(60);
		// The main loop - ends as soon as the window is closed
		while (_data._window->isOpen())
		{
			// Event processing
			sf::Event event;
			while (_data._window->pollEvent(event))
			{
				// Request for closing the window
				if (event.type == sf::Event::Closed)
					_data._window->close();
			}
			// Activate the window for OpenGL rendering
			_data._window->setActive();
			// OpenGL drawing commands go here...
			// End the current frame and display its contents on screen
			_data._window->display();
		}
	}
	inline int Window::GetHeight() {
		return _data._height;
	}
	inline int Window::GetWidth() {
		return _data._width;
	}

}