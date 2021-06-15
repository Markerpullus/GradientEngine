#pragma once

#include "Core.h"

namespace Gradient
{
	class GD_API Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};
	
	// Defined by client
	Application* createApplication();
}
