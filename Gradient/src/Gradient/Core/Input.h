#pragma once

#include "Gradient/EventSystem/KeyCodes.h"
#include "Gradient/EventSystem/MouseCodes.h"
#include "Gradient/Math/Math.h"

namespace Gradient
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button);

		static Vector2 GetMousePos();
	};
}
