#include "czpch.h"
#include <Chemy.h>


class Sandbox : public Chemy::Application
{
public: 
	Sandbox()
	{
	}

	~Sandbox()
	{

	}
};

Chemy::Application* Chemy::CreateApplication()
{
	return new Sandbox();
}