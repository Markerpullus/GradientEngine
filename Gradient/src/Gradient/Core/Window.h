#pragma once

#include "Gradient/Core.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Gradient/EventSystem/Event.h"

#include <functional>

namespace Gradient
{
	class GD_API Window
	{
	private:
		using MainEventCallBack = std::function<void(Event&)>;

		struct WindowData
		{
			GLFWwindow* Window;
			int Width;
			int Height;
			char* Name;

			bool VSync;

			MainEventCallBack EventHandler;
		};

		WindowData data;

		void ConnectEventCallBacks();

	public:
		Window();
		~Window();

		void Init(int w, int h, char* n);

		inline GLFWwindow* GetWin() { return data.Window; }

		inline WindowData GetData() { return data; }

		inline void SetMainEventCallBack(const MainEventCallBack& func) { data.EventHandler = func; }

		void SetVSync(bool vsync);

		inline bool IsVsync() { return data.VSync; }
	};
}
