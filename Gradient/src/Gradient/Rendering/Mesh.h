#pragma once

#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Shader.h"

#include <vector>

namespace Gradient
{
	struct Vertex
	{
		Vector3 Position;
		Vector3 Normal;
		Vector2 TexCoord;
		Vector3 Tangent;
	};

	struct Texture
	{
		unsigned int ID;
		char* Type;
	};

	class Mesh
	{
	private:
		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture> textures;

		unsigned int vao, ibo, vbo;

		void Setup();

	public:
		Mesh(std::vector<Vertex> v, std::vector<unsigned int> i, std::vector<Texture> t);

		void Draw(Shader& shader);
	};
}
