#pragma once

#include "czpch.h"

#include "Application.h"

namespace Chemy {

	Application::Application()
	{
		_window = std::unique_ptr<Window>(Window::Create());

		//setup FPS text
		_fpstext.setFont(_fpsfont);
		_fpstext.setFillColor(sf::Color::White);
		_fpstext.setPosition(sf::Vector2f(0.0f, 0.0f));

		//Start the game
		_isrunning = true;
		CZ_CORE_INFO("Game Started");
		EventSystem::Instance()->Register(EVENT_TYPE::SHUTDOWN, this);

		//End Init
		//Start the Game loop
		this->Run();
	}


	Application::~Application()
	{
	}

	void Application::Update() {
		//Get dt
		float dt = clock.restart().asSeconds();
		if (dt > (1 / MIN_FRAME_RATE)) {
			dt = (1 / MIN_FRAME_RATE);
		}
		_lastfpsupdate += dt;
		if (_showfps) {
			//update FPS
			if (_lastfpsupdate > .5) {
				int fps = 1.0f / dt;
				_fpstext.setString(std::to_string(fps));
				CZ_CORE_INFO("FPS: {}", fps);
				_lastfpsupdate = 0;
			}
			//Draw _fpstext on top layer
			_window->Draw(_fpstext, 1000);
		}


		//update Systems

		
	}
	void Application::Inputs() {

	}
	void Application::Run()
	{
		while (_isrunning) {
			//get inputs
			//Process events
			EventSystem::Instance()->ProcessEvents();
			//update Window
			_window->Update();
			//Update this application
			this->Update();
			//update systems
			//render scenes
			_window->Render();

		}
	}

	void Application::OnEvent(Event event) {
		switch (event.EventID) {
		case EVENT_TYPE::SHUTDOWN:
			_isrunning = false;
			break;
		default:
			break;
		}
	}

}