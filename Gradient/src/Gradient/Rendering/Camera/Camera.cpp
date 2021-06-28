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

	void Camera::DrawModel(Model2D& model, Shader& shader)
	{
		shader.Bind();
		shader.SetUniformMat4f("u_model", model.model);
		shader.SetUniformMat4f("u_view", cam.view);
		shader.SetUniformMat4f("u_proj", cam.projection);

		// TODO: Set light uniforms

		for (auto mesh : model.GetMeshes())
		{
			mesh.Draw(shader);
		}
	}

	void Camera::DrawModel(Model3D& model, Shader& shader)
	{
		shader.Bind();
		shader.SetUniformMat4f("u_model", model.model);
		shader.SetUniformMat4f("u_view", cam.view);
		shader.SetUniformMat4f("u_proj", cam.projection);
		shader.SetUniform3f("u_viewPos", position);

		// TODO: Set light uniforms

		for (auto mesh : model.GetMeshes())
		{
			mesh.Draw(shader);
		}
	}
}