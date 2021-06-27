#include "Gradient/Rendering/Camera/OrthographicCamera.h"

namespace Gradient
{
	OrthographicCamera::OrthographicCamera(Vector3 p, Vector3 r, Vector3 u, float w, float h)
		: Camera(p, r, u, w, h)
	{
		cam.view = glm::lookAt(p, (p + r), u);
		cam.projection = glm::ortho(-w / 2.0f, w / 2.0f, -h / 2.0f, h / 2.0f);
	}

	void OrthographicCamera::SetPosition(Vector3 p)
	{
		Camera::SetPosition(p);
		cam.view = glm::lookAt(position, (position + rotation), up);
	}

	void OrthographicCamera::SetRotation(Vector3 r)
	{
		Camera::SetRotation(r);
		cam.view = glm::lookAt(position, (position + rotation), up);
	}

	void OrthographicCamera::SetUpVector(Vector3 u)
	{
		Camera::SetUpVector(u);
		cam.view = glm::lookAt(position, (position + rotation), up);
	}

	void OrthographicCamera::DrawMesh2D(Mesh2D& mesh)
	{
		// TODO
		return;
	}

	void OrthographicCamera::DrawMesh3D(Mesh3D& mesh)
	{
		// TODO
		return;
	}

}