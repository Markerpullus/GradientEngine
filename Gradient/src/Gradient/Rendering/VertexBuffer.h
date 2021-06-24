#pragma once

#include "Gradient/Math/Math.h"

namespace Gradient
{
	struct Vertex
	{
		Vector3 Position;
		Vector3 Color;
		Vector3 Normal;
		Vector2 TexCoords;
	};

	class VertexBuffer
	{
	public:
		VertexBuffer(const void* data, unsigned int size);
		~VertexBuffer();

		inline unsigned int GetSize() { return size; }

		void Bind();
		void Unbind();

	private:
		unsigned int id;
		unsigned int size;
	};
}

