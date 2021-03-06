#include "Gradient/Rendering/Camera/Camera.h"
#include "Gradient/Core/Log.h"

namespace Gradient
{
	Camera::Camera(float w, float h)
		:width(w), height(h)
	{ }

	void Camera::SetPosition(Vector3 p)
	{
		position = p;
		cam.view = glm::lookAt(position, (position + orientation), up);
	}

	void Camera::SetOrientation(Vector3 r)
	{
		orientation = r;
		cam.view = glm::lookAt(position, (position + orientation), up);
	}

	void Camera::SetUpVector(Vector3 u)
	{
		up = u;
		cam.view = glm::lookAt(position, (position + orientation), up);
	}

	void Camera::SetDimensions(float w, float h)
	{
		width, height = w, h;
		RecalcProjection();
	}
}