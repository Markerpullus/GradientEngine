#pragma once

namespace Gradient
{
	class Texture
	{
	private:
		unsigned int id;
		char* filePath;
		unsigned char* localBuffer;
		int width, height, bpp;

	public:
		Texture(char* path);
		Texture(const int w, const int h);
		~Texture();

		void Bind(unsigned int slot = 0);
		void Unbind();

		inline unsigned int GetID() { return id; }

		inline int GetWidth() { return width; }
		inline int GetHeight() { return height; }
	};

}
