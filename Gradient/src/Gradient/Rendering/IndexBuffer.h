#pragma once

namespace Gradient
{
	class IndexBuffer
	{
	public:
		IndexBuffer(const unsigned int* indices);
		~IndexBuffer();

		void Bind();
		void Unbind();

		inline unsigned int GetCount() const { return count; }

	private:
		unsigned int id;
		unsigned int count;
	};
}
