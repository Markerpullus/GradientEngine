#pragma once

#include "Gradient/Rendering/Camera/Camera.h"

namespace Gradient
{
	class GD_API OrthographicCamera : Camera
	{
	public:
		OrthographicCamera(Vector3 p, Vector3 r, Vector3 u, float w, float h);
		~OrthographicCamera() = default;
	};
}
