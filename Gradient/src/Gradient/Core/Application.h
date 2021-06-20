#pragma once

#include "Gradient/Core.h"
#include "Gradient/Core/Window.h"
#include "Gradient/EventSystem/Event.h"

#include <memory>

namespace Gradient
{
	class GD_API Application
	{
	protected:
		std::unique_ptr<Window> window;
	public:
		Application();
		virtual ~Application();

		void MainEventHandler(Event& e);

		void Run();
	};
	
	// Defined by client
	Application* CreateApplication();
}
