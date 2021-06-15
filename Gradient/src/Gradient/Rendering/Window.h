#pragma once

#include "Gradient/Core.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Gradient
{
	class GD_API Window
	{
	private:
		GLFWwindow* win;
		int width, height;

		char* name;

	public:
		Window();
		~Window();

		void Init(int w, int h, char* n);

		inline GLFWwindow* GetWin() { return win; }

		void EnableVsync(bool vsync);
	};
}
