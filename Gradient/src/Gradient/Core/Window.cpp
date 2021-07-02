#include "Gradient/Core/Window.h"
#include "Gradient/Core/Log.h"
#include "Gradient/EventSystem/KeyEvent.h"
#include "Gradient/EventSystem/MouseEvent.h"
#include "Gradient/EventSystem/WindowEvent.h"

namespace Gradient
{	

	void Window::ConnectEventCallBacks()
	{
		// Key Events
		glfwSetKeyCallback(data.win, 
			[](GLFWwindow* win, int key, int scancode, int action, int mods)
			{
				Window* self = (Window*)glfwGetWindowUserPointer(win);
				KeyCode k = (KeyCode)key;
				switch (action)
				{
				case GLFW_PRESS:
					self->EventHandler(KeyDownEvent(k));
					break;
				case GLFW_RELEASE:
					self->EventHandler(KeyUpEvent(k));
					break;
				case GLFW_REPEAT:
					self->EventHandler(KeyRepeatEvent(k));
					break;
				}
			});

		// Type Event
		glfwSetCharCallback(data.win,
			[](GLFWwindow* win, unsigned int key)
			{
				Window* self = (Window*)glfwGetWindowUserPointer(win);
				self->EventHandler(KeyTypedEvent((KeyCode)key));
			});

		// Mouse Button Event
		glfwSetMouseButtonCallback(data.win,
			[](GLFWwindow* win, int button, int action, int mods)
			{
				Window* self = (Window*)glfwGetWindowUserPointer(win);
				switch (action)
				{
				case GLFW_PRESS:
					self->EventHandler(MouseDownEvent((MouseCode)button));
					break;
				case GLFW_RELEASE:
					self->EventHandler(MouseUpEvent((MouseCode)button));
					break;
				}
			});

		// Mouse Scroll Event
		glfwSetScrollCallback(data.win,
			[](GLFWwindow* win, double xOffset, double yOffset)
			{
				Window* self = (Window*)glfwGetWindowUserPointer(win);
				self->EventHandler(MouseScrolledEvent(xOffset, yOffset));
			});

		// Mouse Move Event
		glfwSetCursorPosCallback(data.win, 
			[](GLFWwindow* win, double xPos, double yPos)
			{
				Window* self = (Window*)glfwGetWindowUserPointer(win);
				self->EventHandler(MouseMovedEvent(xPos, yPos));
			});

		// Mouse Enter/Leave Window Event
		glfwSetCursorEnterCallback(data.win, 
			[](GLFWwindow* win, int entered)
			{
				Window* self = (Window*)glfwGetWindowUserPointer(win);
				entered ? self->EventHandler(MouseEnterWindowEvent())
					: self->EventHandler(MouseLeaveWindowEvent());
			});

		// Window Resize Event
		glfwSetWindowSizeCallback(data.win,
			[](GLFWwindow* win, int width, int height)
			{
				Window* self = (Window*)glfwGetWindowUserPointer(win);
				self->EventHandler(WindowResizeEvent(width, height));
			});

		// Window Close Event
		glfwSetWindowCloseCallback(data.win, 
			[](GLFWwindow* win)
			{
				Window* self = (Window*)glfwGetWindowUserPointer(win);
				self->EventHandler(WindowCloseEvent());
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

		data.win = glfwCreateWindow(w, h, n, NULL, NULL);
		data.width = w;
		data.height = h;
		data.name = n;
		glfwSetWindowUserPointer(data.win, reinterpret_cast<void*>(this));

		if (data.win == NULL)
		{
			GD_CORE_CRITICAL("Failed to create window");
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(data.win);

		glfwSwapInterval(1);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			GD_CORE_CRITICAL("Failed to initialize glad");
			glfwTerminate();
			return;
		}

		glViewport(0, 0, w, h);
		GD_CORE_INFO("Using OpenGL version: {0}", glGetString(GL_VERSION));
		glfwSetInputMode(data.win, GLFW_STICKY_KEYS, GL_TRUE);

		ConnectEventCallBacks();
	}

	void Window::SetVSync(bool vsync)
	{
		glfwSwapInterval(vsync);
		VSync = vsync;
	}
}