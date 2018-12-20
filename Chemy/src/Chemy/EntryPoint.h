#pragma once


#ifdef CHEMY_PLATFORM_WINDOWS

extern Chemy::Application* Chemy::CreateApplication();

int main(int argc, char** argv)
{

	Chemy::Log::Init();
	CZ_CORE_WARN("Initialized Log!");
	int a = 5;
	int b = 6;
	CZ_ERROR("Hello! Var={0}","Test");

	auto app = Chemy::CreateApplication();
	app->Run();
	delete app;
	return 1;
}

#endif