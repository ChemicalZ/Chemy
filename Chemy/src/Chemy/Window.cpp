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
		_data._window = std::unique_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(_data._height, _data._width), _data._title));
		_data._window->setFramerateLimit(60);

		CZ_CORE_INFO("Window {} ({},{}) created", _data._title, _data._height, _data._width);
	}

	Window* Window::Create(const WindowProps& props) {
		return new Window(props);
	}

	//TODO: Poll for events like every other function
	void Window::Update() {

		sf::Event event;
		while (_data._window->pollEvent(event))
		{
			// Request for closing the window
			if (event.type == sf::Event::Closed) {
				EventSystem::Instance()->SendEvent(Event(EVENT_TYPE::SHUTDOWN, NULL));
				_data._window->close();
			}
		}
	}
	//Adds items to the draw que
	//Param 1: sf::Drawable
	//Param 2: int drawowrder
	void Window::Draw(const sf::Drawable& data, int order = 100) {
		_drawqueue.emplace(order, data);
	}
	void Window::Render() {
		//Set the window active
		_data._window->setActive();
		//Clear the window
		_data._window->clear(sf::Color::Black);
		//Go through the queue and draw the items in order
		for (auto it = _drawqueue.begin(); it != _drawqueue.end();it++) {
			_data._window->draw(it->second);
		}
		//Show the frame
		_data._window->display();
		_drawqueue.clear();
	}

	inline int Window::GetHeight() {
		return _data._height;
	}
	inline int Window::GetWidth() {
		return _data._width;
	}

}