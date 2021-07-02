#pragma once

#include "Gradient/Core.h"
#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Shader.h"
#include "Gradient/Rendering/Texture.h"

#include <vector>

namespace Gradient
{
	struct Vertex3D
	{
		Vector3 position;
		Vector3 normal;
		Vector2 texCoord;
	};

	class GD_API Mesh3D
	{
	private:
		std::vector<Vertex3D> vertices;
		std::vector<unsigned int> indices;
		Material material;

		unsigned int vao, ibo, vbo;

		void Setup();

	public:
		Mesh3D(std::vector<Vertex3D>& v, std::vector<unsigned int>& i, Material& m);

		void Draw(Shader& shader);
	};
}
