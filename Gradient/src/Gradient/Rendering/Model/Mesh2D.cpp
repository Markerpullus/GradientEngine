#include "Gradient/Rendering/Model/Mesh2D.h"
#include "glad/glad.h"

namespace Gradient
{
	void Mesh2D::Setup()
	{
		// Create vao, ibo, vbo
		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &ibo);
		glGenBuffers(1, &vbo);

		glBindVertexArray(vao);
		// Load buffer data
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex2D), &vertices[0], GL_STATIC_DRAW);

		// Load index buffer data
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

		// Vertex Attrib Pointers
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (const void*)0); // Position
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2D), (const void*)offsetof(Vertex2D, TexCoord)); // TexCoords

		glBindVertexArray(0);
	}

	Mesh2D::Mesh2D(std::vector<Vertex2D>& v, std::vector<unsigned int>& i, std::vector<Texture>& t)
		: vertices(v), indices(i), textures(t)
	{
		Setup();
	}

	void Mesh2D::Draw(Shader& shader)
	{
		for (unsigned int i = 0; i < textures.size(); i++)
		{
			glActiveTexture(GL_TEXTURE0 + i);

			shader.SetUniform1i("tex", i);
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