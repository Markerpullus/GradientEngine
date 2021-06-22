#include "Gradient/Core/Window.h"
#include "Gradient/Core/Log.h"
#include "Gradient/EventSystem/KeyEvent.h"

namespace Gradient
{	

	void Window::ConnectEventCallBacks()
	{
		// Key Events
		glfwSetKeyCallback(data.Win,
			[](GLFWwindow* win, int key, int scancode, int action, int mods)
			{
				Window* self = (Window*)glfwGetWindowUserPointer(win);
				switch (action)
				{
				case GLFW_PRESS:
					self->EventHandler(KeyDownEvent((KeyCode)key));
					break;
				case GLFW_RELEASE:
					self->EventHandler(KeyUpEvent((KeyCode)key));
					break;
				case GLFW_REPEAT:
					self->EventHandler(KeyRepeatEvent((KeyCode)key));
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

		data.Win = glfwCreateWindow(w, h, n, NULL, NULL);
		data.Width = w;
		data.Height = h;
		data.Name = n;
		glfwSetWindowUserPointer(data.Win, reinterpret_cast<void*>(this));

		if (data.Win == NULL)
		{
			GD_CORE_CRITICAL("Failed to create window");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(data.Win);

		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			GD_CORE_CRITICAL("Failed to initialize glad");
			glfwTerminate();
			return;
		}

		glViewport(0, 0, w, h);
		GD_CORE_INFO("Using OpenGL version: {0}", glGetString(GL_VERSION));
		glfwSetInputMode(data.Win, GLFW_STICKY_KEYS, GL_TRUE);

		ConnectEventCallBacks();
	}

	void Window::SetVSync(bool vsync)
	{
		glfwSwapInterval(vsync);
		VSync = vsync;
	}
}