#pragma once

namespace Gradient
{
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

