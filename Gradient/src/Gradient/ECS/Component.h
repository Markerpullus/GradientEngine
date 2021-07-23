#pragma once

#include "Gradient/Core.h"
#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Camera/OrthographicCamera.h"
#include "Gradient/Rendering/Camera/PerspectiveCamera.h"

namespace Gradient
{
	namespace Component
	{
		struct GD_API Transform
		{
			Vector3 translation = Vector3(0.0f);
			//Vector3 rotation = Vector3(1.0f); // pitch, roll, yaw
			Quaternion rotation = Quaternion(Vector3(0.0f, 0.0f, 0.0f));
			Vector3 scale = Vector3(1.0f);
		};

		struct GD_API OrthographicCamera
		{
			float width = 800.0f, height = 600.0f;
			float zNear = 0.01f, zFar = 100.0f;
		};

		struct GD_API PerspectiveCamera
		{
			float width = 800.0f, height = 600.0f;
			float zNear = 0.01f, zFar = 100.0f;
			float fov = 90.0f;
		};
	}
}