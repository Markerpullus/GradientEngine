#include "Gradient/Rendering/Camera/OrthographicCamera.h"

namespace Gradient
{
	void OrthographicCamera::RecalcProjection()
	{
		cam.projection = glm::ortho(-width / 2.0f, width / 2.0f, -height / 2.0f, height / 2.0f, zNear, zFar);
	}

	OrthographicCamera::OrthographicCamera(float w, float h)
		: Camera(w, h)
	{
		cam.view = glm::lookAt(position, (position + direction), up);
		RecalcProjection();
	}

	void OrthographicCamera::SetZNear(float znear)
	{
		zNear = znear;
		RecalcProjection();
	}

	void OrthographicCamera::SetZFar(float zfar)
	{
		zFar = zfar;
		RecalcProjection();
	}
}