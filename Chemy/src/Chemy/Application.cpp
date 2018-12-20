#pragma once

#include "czpch.h"

#include "Application.h"

namespace Chemy {

	Application::Application()
	{
		_window = std::unique_ptr<Window>(Window::Create());
	}


	Application::~Application()
	{
	}
	
	void Application::Run()
	{
		_window->Update();
	}
}