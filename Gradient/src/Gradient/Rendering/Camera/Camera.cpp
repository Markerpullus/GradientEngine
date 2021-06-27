#include "Gradient/Rendering/Camera/Camera.h"

namespace Gradient
{
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

	void Camera::DrawModel(Model2D& model)
	{
		Shader shader("../Gradient/src/Gradient/Shaders/2D.glsl");
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

	void Camera::DrawModel(Model3D& model)
	{
		Shader shader("../Gradient/src/Gradient/Shaders/Phong.glsl");
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