#include "Gradient/Rendering/VertexArray.h"

namespace Gradient
{
	VertexArray::VertexArray(VertexBuffer& vb)
	{
		glGenVertexArrays(1, &id);
		glBindVertexArray(id);
		vertexBuffer = &vb;
	}

	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &id);
	}

	void VertexArray::AddBuffer(VertexBufferLayout& layout)
	{
		Bind();
		vertexBuffer->Bind();
		std::vector<VertexAttribute> elements = layout.GetElements();
		unsigned int pointer = 0;
		for (auto attrib : elements)
		{
			glVertexAttribPointer(attrib.index, attrib.count, attrib.type, attrib.normalized,
				layout.GetStride(), (const void*)pointer);
			pointer += attrib.count * attrib.GetSizeOfType();
			glEnableVertexAttribArray(attrib.index);
		}
	}

	void VertexArray::Bind()
	{
		glBindVertexArray(id);
	}

	void VertexArray::Unbind()
	{
		glBindVertexArray(0);
	}

	VertexBufferLayout::VertexBufferLayout()
	{
		stride = 0;
		currentAttrib = 0;
	}

	void VertexBufferLayout::Push(unsigned int count, unsigned int type, bool normalized)
	{
		struct VertexAttribute va = { currentAttrib, count, type, normalized };
		elements.push_back(va);
		stride += count * va.GetSizeOfType();
		currentAttrib++;
	}
}