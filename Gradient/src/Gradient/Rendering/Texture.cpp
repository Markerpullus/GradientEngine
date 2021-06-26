#include "Gradient/Core/Log.h"
#include "Gradient/Rendering/Texture.h"
#include "glad/glad.h"
#include "stb/stb_image.h"

namespace Gradient
{
	Texture::Texture(const char* path, TextureType type)
		: Type(type)
	{
		std::string filename = std::string(path);
		filename = path;

		glGenTextures(1, &ID);

		int width, height, nrComponents;
		stbi_set_flip_vertically_on_load(1);
		unsigned char* data = stbi_load(filename.c_str(), &width, &height, &nrComponents, 0);
		if (data)
		{
			GLenum format;
			if (nrComponents == 1)
				format = GL_RED;
			else if (nrComponents == 3)
				format = GL_RGB;
			else if (nrComponents == 4)
				format = GL_RGBA;

			glBindTexture(GL_TEXTURE_2D, ID);
			glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			stbi_image_free(data);
		}
		else
		{
			GD_CORE_ERROR("Texture failed to load at path: {}", path);
			stbi_image_free(data);
		}
	}
}