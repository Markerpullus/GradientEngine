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

		for (auto mesh : model.GetMeshes())
		{
			mesh.Draw(shader);
		}
	}

	void Camera::DrawModel(Model3D& model, Shader& shader, std::vector<Light*>& lights)
	{
		shader.Bind();
		shader.SetUniformMat4f("u_model", model.model);
		shader.SetUniformMat4f("u_view", cam.view);
		shader.SetUniformMat4f("u_proj", cam.projection);
		shader.SetUniform3f("u_viewPos", position);

		int pointLightsSize = 0, dirLightsSize = 0;
		for (int i = 0; i < lights.size(); i++)
		{
			switch (lights.at(i)->type)
			{
			case LightType::PointLight:
			{
				pointLightsSize++;
				PointLight* pointLight = dynamic_cast<PointLight*>(lights.at(i));
				std::string num = std::to_string(i);
				shader.SetUniform3f("u_pointLights[" + num + "].Ambient", pointLight->ambient);
				shader.SetUniform3f("u_pointLights[" + num + "].Diffuse", pointLight->diffuse);
				shader.SetUniform3f("u_pointLights[" + num + "].Specular", pointLight->specular);
				shader.SetUniform3f("u_pointLights[" + num + "].Position", pointLight->position);
				break;
			}
			case LightType::DirectionalLight:
			{
				dirLightsSize++;
				// TODO
				break;
			}
			}
		}

		shader.SetUniform1i("u_pointLightsSize", pointLightsSize);

		for (auto mesh : model.GetMeshes())
		{
			mesh.Draw(shader);
		}
	}
}