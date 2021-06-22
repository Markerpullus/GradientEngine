#pragma once

#include "Gradient/Core.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Gradient/EventSystem/Event.h"
#include "boost/function.hpp"

namespace Gradient
{
	class GD_API Window
	{
	private:
		using MainEventCallBack = boost::function<void(Event&)>;

		struct WindowData
		{
			GLFWwindow* Win;
			int Width;
			int Height;
			char* Name;
		};

		WindowData data;

		bool VSync;

		MainEventCallBack EventHandler;

		void ConnectEventCallBacks();

	public:
		Window();
		~Window();

		void Init(int w, int h, char* n);

		inline GLFWwindow* GetWin() { return data.Win; }

		inline WindowData GetData() { return data; }

		inline void SetMainEventCallBack(const MainEventCallBack& func) { EventHandler = func; }

		void SetVSync(bool vsync);

		inline bool IsVsync() { return VSync; }
	};
}
