#include "Gradient/Rendering/Camera/Camera.h"
#include "Gradient/Core/Log.h"

namespace Gradient
{
	Camera::Camera(Vector3 p, Vector3 r, Vector3 u, float w, float h)
		: position(p), rotation(r), up(u), width(w), height(h)
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