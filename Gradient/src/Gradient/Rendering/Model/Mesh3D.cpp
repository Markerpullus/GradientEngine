#include "Gradient/Rendering/Model/Mesh3D.h"
#include "glad/glad.h"

namespace Gradient
{
	void Mesh3D::Setup()
	{
		// Create vao, ibo, vbo
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &ibo);
		glGenBuffers(1, &vbo);

		glBindVertexArray(vao);
		// Load buffer data
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex3D), &vertices[0], GL_STATIC_DRAW);

		// Load index buffer data
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

		// Vertex Attrib Pointers
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const void*)0); // Position
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const void*)offsetof(Vertex3D, Normal)); // Normals
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const void*)offsetof(Vertex3D, TexCoord)); // TexCoords
		glEnableVertexAttribArray(3);
		glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (const void*)offsetof(Vertex3D, Tangent)); // Tangents

		glBindVertexArray(0);
	}

	Mesh3D::Mesh3D(std::vector<Vertex3D>& v, std::vector<unsigned int>& i, std::vector<Texture>& t)
		: vertices(v), indices(i), textures(t)
	{
		Setup();
	}

	void Mesh3D::Draw(Shader& shader)
	{
		for (unsigned int i = 0; i < textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			switch (textures.at(i).Type)
			{
			case TextureType::Diffuse:
				shader.SetUniform1i("u_mat.Diffuse", i);
				break;
			case TextureType::Specular:
				shader.SetUniform1i("u_mat.Specular", i);
				break;
			}
			glBindTexture(GL_TEXTURE_2D, textures.at(i).ID);
		}

		// Bind and draw
		glBindVertexArray(vao);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		shader.Bind();
		glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, (const void*)0);

		// Clean up
		glBindVertexArray(0);
		glActiveTexture(GL_TEXTURE0);
		shader.Unbind();
	}
}