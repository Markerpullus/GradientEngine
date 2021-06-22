#pragma once

#include "Gradient/EventSystem/KeyCodes.h"
#include "Gradient/EventSystem/MouseCodes.h"
#include "glm/vec2.hpp"

namespace Gradient
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);

		static glm::vec2 GetMousePos();
	};
}
