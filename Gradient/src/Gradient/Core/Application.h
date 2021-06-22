#pragma once

#include "Gradient/Core.h"
#include "Gradient/Core/Window.h"
#include "Gradient/EventSystem/Event.h"
#include "Gradient/EventSystem/KeyEvent.h"

#include <memory>

namespace Gradient
{
	class GD_API Application
	{
	protected:
		std::unique_ptr<Window> window;

		static Application* self;
	public:
		Application();
		virtual ~Application();

		inline static Application* GetSelf() { return self; }

		inline Window& GetWindow() { return *window; }

		void MainEventHandler(Event& e);

		void Run();
	};
	
	// Defined by client
	Application* CreateApplication();
}
