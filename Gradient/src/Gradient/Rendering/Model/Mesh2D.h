#pragma once

#include "Gradient/Core.h"
#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Shader.h"
#include "Gradient/Rendering/Texture.h"

#include <vector>

namespace Gradient
{
	struct Vertex2D
	{
		Vector3 position;
		Vector2 texCoord;
	};

	class GD_API Mesh2D
	{
	private:
		std::vector<Vertex2D> vertices;
		std::vector<unsigned int> indices;
		Texture texture;

		unsigned int vao, ibo, vbo;

		void Setup();

	public:
		Mesh2D(std::vector<Vertex2D>& v, std::vector<unsigned int>& i, Texture t);

		void Draw(Shader& shader);
	};
}
