#pragma once

#include "GLFW/glfw3.h"

class Window
{
private:
	GLFWwindow* win;

public:
	Window();
	~Window();
};

