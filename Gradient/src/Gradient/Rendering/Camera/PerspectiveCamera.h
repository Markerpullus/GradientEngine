#pragma once

#include "Gradient/Rendering/Camera/Camera.h"

namespace Gradient
{
	class GD_API PerspectiveCamera : public Camera
	{
	private:
		float fov;
		void RecalcProjection();

	public:
		PerspectiveCamera(float w, float h, float fov, float znear, float zfar);
		~PerspectiveCamera() = default;

		void SetFov(float nfov);

		void SetZNear(float znear);

		void SetZFar(float zfar);
	};
}
