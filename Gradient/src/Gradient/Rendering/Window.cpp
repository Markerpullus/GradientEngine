#include "Window.h"
#include "Gradient/Core/Log.h"

namespace Gradient
{	
	Window::Window()
	{
		
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::Init(int w, int h, char* n)
	{
		width = w;
		height = h;
		name = n;
		if (!glfwInit())
		{
			GD_CORE_CRITICAL("Failed to initialize glfw");
			return;
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		win = glfwCreateWindow(width, height, name, NULL, NULL);

		if (win == NULL)
		{
			GD_CORE_CRITICAL("Failed to create window");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(win);

		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			GD_CORE_CRITICAL("Failed to initialize glad");
			glfwTerminate();
			return;
		}

		glViewport(0, 0, width, height);
		GD_CORE_INFO("Using OpenGL version: {0}", glGetString(GL_VERSION));
		glfwSetInputMode(win, GLFW_STICKY_KEYS, GL_TRUE);
	}

	void Window::EnableVsync(bool vsync)
	{
		glfwSwapInterval(vsync);
	}
}