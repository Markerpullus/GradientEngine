#pragma once

#include "Gradient/Rendering/Camera/Camera.h"

namespace Gradient
{
	class GD_API PerspectiveCamera : public Camera
	{
	private:
		float fov = 90.0f;
		virtual void RecalcProjection() override;

	public:
		PerspectiveCamera(float w, float h);
		~PerspectiveCamera() = default;

		void SetFov(float nfov);

		void SetZNear(float znear);

		void SetZFar(float zfar);
	};
}
