#include "Application.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Gradient
{
	Application::Application()
	{
		window = new Window();
	}

	Application::~Application()
	{
		delete window;
	}

	void Application::run()
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