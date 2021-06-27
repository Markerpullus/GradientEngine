#pragma once

#include "Gradient/Rendering/Camera/Camera.h"

namespace Gradient
{
	class GD_API PerspectiveCamera : Camera
	{
	private:
		float zNear, zFar;

	public:
		PerspectiveCamera(Vector3 p, Vector3 r, Vector3 u, float w, float h, float fov, float znear, float zfar);
		~PerspectiveCamera() = default;
	};
}
