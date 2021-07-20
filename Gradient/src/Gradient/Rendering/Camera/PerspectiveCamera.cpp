#include "Gradient/Rendering/Camera/PerspectiveCamera.h"

namespace Gradient
{
	void PerspectiveCamera::RecalcProjection()
	{
		cam.projection = glm::ortho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f) *
			glm::perspective(glm::radians(fov), width / height, zNear, zFar);
	}

	PerspectiveCamera::PerspectiveCamera(float w, float h, float fov, float znear, float zfar)
		: Camera(w, h)
	{
		zNear = znear;
		zFar = zfar;
		cam.view = glm::lookAt(position, (position + rotation), up);
		RecalcProjection();
	}

	void PerspectiveCamera::SetFov(float nfov)
	{
		fov = nfov;
		RecalcProjection();
	}

	void PerspectiveCamera::SetZNear(float znear)
	{
		zNear = znear;
		RecalcProjection();
	}

	void PerspectiveCamera::SetZFar(float zfar)
	{
		zFar = zfar;
		RecalcProjection();
	}
}