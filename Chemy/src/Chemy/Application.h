#pragma once

#include "Core.h"
#include "Window.h"


namespace Chemy {

	class CHEMY_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> _window;
	};

	//To be defined in the client
	Application* CreateApplication();
}