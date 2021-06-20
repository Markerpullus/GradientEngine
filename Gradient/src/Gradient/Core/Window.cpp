#include "Gradient/Core/Window.h"
#include "Gradient/Core/Log.h"
#include "Gradient/EventSystem/KeyEvent.h"

namespace Gradient
{	

	void Window::ConnectEventCallBacks()
	{
		// Key Events
		glfwSetKeyCallback(data.Window,
			[](GLFWwindow* win, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(win);
				switch (action)
				{
				case GLFW_PRESS:
					data.EventHandler(KeyDownEvent((KeyCode)key));
					break;
				case GLFW_RELEASE:
					data.EventHandler(KeyUpEvent((KeyCode)key));
					break;
				case GLFW_REPEAT:
					data.EventHandler(KeyRepeatEvent((KeyCode)key));
					break;
				}
			});
	}

	Window::Window()
	{
		
	}

	Window::~Window()
	{
		glfwTerminate();
	}

	void Window::Init(int w, int h, char* n)
	{
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

		data.Window = glfwCreateWindow(w, h, n, NULL, NULL);
		data.Width = w;
		data.Height = h;
		data.Name = n;

		if (data.Window == NULL)
		{
			GD_CORE_CRITICAL("Failed to create window");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(data.Window);

		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			GD_CORE_CRITICAL("Failed to initialize glad");
			glfwTerminate();
			return;
		}

		glViewport(0, 0, w, h);
		GD_CORE_INFO("Using OpenGL version: {0}", glGetString(GL_VERSION));
		glfwSetInputMode(data.Window, GLFW_STICKY_KEYS, GL_TRUE);

		ConnectEventCallBacks();
	}

	void Window::SetVSync(bool vsync)
	{
		glfwSwapInterval(vsync);
		data.VSync = vsync;
	}
}