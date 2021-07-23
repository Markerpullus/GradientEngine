#pragma once

#include "Gradient/Rendering/Camera/Camera.h"

namespace Gradient
{
	class GD_API OrthographicCamera : public Camera
	{
	private:
		virtual void RecalcProjection() override;

	public:
		OrthographicCamera(float w, float h);
		~OrthographicCamera() = default;

		void SetZNear(float znear);

		void SetZFar(float zfar);
	};
}
