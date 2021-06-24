#pragma once

#include "glad/glad.h"
#include "Gradient/Core.h"
#include "Gradient/Rendering/VertexBuffer.h"

#include <vector>

namespace Gradient
{
	struct VertexAttribute
	{
		unsigned int index;
		unsigned int count;
		unsigned int type;
		bool normalized;
		unsigned int GetSizeOfType()
		{
			switch (type)
			{
			case GL_FLOAT: return sizeof(float);
			case GL_UNSIGNED_INT: return sizeof(unsigned int);
			case GL_UNSIGNED_BYTE: return sizeof(char);
			}
			ASSERT(false);
			return 0;
		}
	};

	class VertexBufferLayout
	{
	private:
		std::vector<VertexAttribute> elements;
		unsigned int stride;
		unsigned int currentAttrib;

	public:
		VertexBufferLayout();

		void Push(unsigned int count, unsigned int type, bool normalized);
		inline std::vector<VertexAttribute> GetElements() { return elements; }
		inline unsigned int GetStride() { return stride; }
	};

	class VertexArray
	{
	private:
		VertexBuffer* vertexBuffer;
		unsigned int id;

	public:
		VertexArray(VertexBuffer& vb);
		~VertexArray();

		void AddBuffer(VertexBufferLayout& layout);
		void Bind();
		void Unbind();
		inline VertexBuffer* GetBuffer() { return vertexBuffer; }
	};
}
