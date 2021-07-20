#pragma once

#include "Gradient/Rendering/Camera/Camera.h"

namespace Gradient
{
	class GD_API OrthographicCamera : public Camera
	{
	private:
		void RecalcProjection();

	public:
		OrthographicCamera(float w, float h, float znear, float zfar);
		~OrthographicCamera() = default;

		void SetZNear(float znear);

		void SetZFar(float zfar);
	};
}
