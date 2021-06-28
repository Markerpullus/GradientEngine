#include "Gradient/Rendering/Camera/OrthographicCamera.h"

namespace Gradient
{
	OrthographicCamera::OrthographicCamera(Vector3 p, Vector3 r, Vector3 u, float w, float h, float znear, float zfar)
		: Camera(p, r, u, w, h), zNear(znear), zFar(zfar)
	{
		cam.view = glm::lookAt(p, (p + r), u);
		cam.projection = glm::ortho(-w / 2.0f, w / 2.0f, -h / 2.0f, h / 2.0f, znear, zfar);
	}
}