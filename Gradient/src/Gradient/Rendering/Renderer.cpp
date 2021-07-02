#include "Gradient/Rendering/Renderer.h"
#include "GLFW/glfw3.h"

namespace Gradient
{
	void Renderer::BeginFrame()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Renderer::EndFrame()
	{
		glfwSwapBuffers(glfwGetCurrentContext());
		glfwPollEvents();
	}

	void Renderer::DrawModel(Model2D& model, Shader& shader)
	{
		shader.Bind();
		shader.SetUniformMat4f("u_model", model.model);
		shader.SetUniformMat4f("u_view", camera.cam.view);
		shader.SetUniformMat4f("u_proj", camera.cam.projection);

		for (auto mesh : model.GetMeshes())
		{
			mesh.Draw(shader);
		}
	}

	void Renderer::DrawModel(Model3D& model, Shader& shader, std::vector<Light*>& lights)
	{
		shader.Bind();
		shader.SetUniformMat4f("u_model", model.model);
		shader.SetUniformMat4f("u_view", camera.cam.view);
		shader.SetUniformMat4f("u_proj", camera.cam.projection);
		shader.SetUniform3f("u_viewPos", camera.position);

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