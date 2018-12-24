#pragma once

#include "Core.h"
#include "Window.h"
#include "AssetManager.h"
#include "EventSystem/EventSystem.h"

namespace Chemy {

	class CHEMY_API Application : public Listener
	{

	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event event);
		void Inputs();

		void Update();

	protected:
		//Pointer to window
		std::unique_ptr<Window> _window;
		//Game Clock
		sf::Clock clock;
		//Is the gamerunning?
		bool _isrunning = false;

		//Show fps??
		bool _showfps = true;
		float _lastfpsupdate = 0;
		//Asset manager
		Chemy::AssetManager _assets;
		//Font for FPS
		sf::Font _fpsfont = _assets.LoadFont("FPS", "Freshman.ttf");
		sf::Text _fpstext;

		//Game Constants
		float MIN_FRAME_RATE = 30.0f;
		float MAX_FRAME_RATE = 60.0f;
	};

	//To be defined in the client
	Application* CreateApplication();
	
}