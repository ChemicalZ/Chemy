#pragma once


#ifdef CHEMY_PLATFORM_WINDOWS

extern Chemy::Application* Chemy::CreateApplication();

void main(int argc, char** argv)
{
	auto app = Chemy::CreateApplication();
	app->Run();
	delete app;
}

#endif