#pragma once

#include "Gradient/Core.h"
#include "Gradient/Rendering/Window.h"

namespace Gradient
{
	class GD_API Application
	{
	protected:
		Window* window;
	public:
		Application();
		virtual ~Application();

		void run();
	};
	
	// Defined by client
	Application* CreateApplication();
}
