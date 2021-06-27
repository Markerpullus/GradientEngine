#include "Gradient/Rendering/Camera/PerspectiveCamera.h"

namespace Gradient
{
	PerspectiveCamera::PerspectiveCamera(Vector3 p, Vector3 r, Vector3 u, float w, float h, float fov, float znear, float zfar)
		: Camera(p, r, u, w, h), zNear(znear), zFar(zfar)
	{
		cam.view = glm::lookAt(p, (p + r), u);
		cam.projection = glm::ortho(-w / 2.0f, w / 2.0f, -h / 2.0f, h / 2.0f) *
			glm::perspective(glm::radians(fov), w / h, znear, zfar);
	}

	void PerspectiveCamera::SetPosition(Vector3 p)
	{
		Camera::SetPosition(p);
		cam.view = glm::lookAt(position, (position + rotation), up);
	}

	void PerspectiveCamera::SetRotation(Vector3 r)
	{
		Camera::SetRotation(r);
		cam.view = glm::lookAt(position, (position + rotation), up);
	}

	void PerspectiveCamera::SetUpVector(Vector3 u)
	{
		Camera::SetUpVector(u);
		cam.view = glm::lookAt(position, (position + rotation), up);
	}

	void PerspectiveCamera::DrawMesh2D(Mesh2D& mesh)
	{
		// TODO
		return;
	}

	void PerspectiveCamera::DrawMesh3D(Mesh3D& mesh)
	{
		// TODO
		return;
	}

}