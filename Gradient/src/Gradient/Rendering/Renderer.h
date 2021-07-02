#pragma once

#include "Gradient/Core.h"
#include "glad/glad.h"
#include "Gradient/Rendering/Camera/Camera.h"
#include "Gradient/Rendering/Model/Model.h"

namespace Gradient
{
	class GD_API Renderer
	{
	private:
		Camera& camera;

	public:
		Renderer(Camera& cam)
			: camera(cam)
		{ }

		~Renderer() = default;

		inline void BindCamera(Camera& cam) { camera = cam; }

		inline void SetClearColor(Vector3 color) { glClearColor(color.x, color.y, color.z, 1.0f); }

		void BeginFrame();

		void EndFrame();

		void DrawModel(Model2D& model, Shader& shader);

		void DrawModel(Model3D& model, Shader& shader, std::vector<Light*>& lights);
	};
}