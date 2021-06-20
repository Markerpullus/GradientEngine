#include "Gradient/Core/Application.h"
#include "Gradient/Core/Log.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Gradient
{
	Application::Application()
	{
		window = std::make_unique<Window>(Window());
		window->SetMainEventCallBack(GD_BIND_EVENT_CALLBACK(Application::MainEventHandler));
	}

	Application::~Application()
	{
		
	}

	void Application::MainEventHandler(Event& e)
	{
		GD_CORE_INFO("Key is pressed");
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