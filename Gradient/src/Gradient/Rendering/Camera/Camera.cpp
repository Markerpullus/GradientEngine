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
		cam.view = glm::lookAt(position, (position + rotation), up);
	}

	void Camera::SetRotation(Vector3 r)
	{
		rotation = r;
		cam.view = glm::lookAt(position, (position + rotation), up);
	}

	void Camera::SetUpVector(Vector3 u)
	{
		up = u;
		cam.view = glm::lookAt(position, (position + rotation), up);
	}
}