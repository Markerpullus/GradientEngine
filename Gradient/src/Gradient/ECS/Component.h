#pragma once

#include "Gradient/Core.h"
#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Camera/OrthographicCamera.h"
#include "Gradient/Rendering/Camera/PerspectiveCamera.h"

namespace Gradient
{
	namespace Components
	{
		struct GD_API Transform
		{
			Vector3 translation = Vector3(0.0f);
			Vector3 rotation = Vector3(1.0f);
			Vector3 scale = Vector3(1.0f);
		};
	}
}