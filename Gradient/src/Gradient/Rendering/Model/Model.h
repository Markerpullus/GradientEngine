#pragma once

#include "Gradient/Core.h"
#include "Gradient/Rendering/Model/Mesh2D.h"
#include "Gradient/Rendering/Model/Mesh3D.h"

namespace Gradient
{
	class GD_API Model2D
	{
	private:
		Matrix4 model;
		std::vector<Mesh2D> meshes;

	public:
		Model2D(std::vector<Mesh2D> m, Matrix4 modelMat = Matrix4(1.0f))
			: meshes(m), model(modelMat)
		{ }

		inline std::vector<Mesh2D> GetMeshes() { return meshes; }

		inline void SetModelMatrix(Matrix4 modelMat) { model = modelMat; }
	};

	class GD_API Model3D
	{
	private:
		Matrix4 model;
		std::vector<Mesh3D> meshes;

	public:
		Model3D(std::vector<Mesh3D> m, Matrix4 modelMat = Matrix4(1.0f))
			: meshes(m), model(modelMat)
		{ }

		inline std::vector<Mesh3D> GetMeshes() { return meshes; }

		inline void SetModelMatrix(Matrix4 modelMat) { model = modelMat; }
	};
}
