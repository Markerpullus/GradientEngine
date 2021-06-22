#include "Gradient/Core/Application.h"
#include "Gradient/Core/Log.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "boost/bind.hpp"

namespace Gradient
{
	Application::Application()
	{
		window = std::make_unique<Window>(Window());
		window->SetMainEventCallBack(boost::bind(&Application::MainEventHandler, this, _1));
	}

	Application::~Application()
	{
		
	}

	void Application::MainEventHandler(Event& e)
	{
		switch (e.name)
		{
		case EventName::KeyDown:
			GD_CORE_INFO("Key Down");
			break;
		case EventName::KeyUp:
			GD_CORE_INFO("Key Up");
			break;
		case EventName::KeyRepeat:
			GD_CORE_INFO("Key Repeat");
			break;
		}
	}

	void Application::Run()
	{
		while (!glfwWindowShouldClose(window->GetWin()))
		{
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glfwSwapBuffers(window->GetWin());
			glfwPollEvents();
		}
	}
}