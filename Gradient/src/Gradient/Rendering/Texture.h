#pragma once

#include <string>

namespace Gradient
{
	enum class TextureType
	{
		Default = 0,
		Diffuse,
		Specular
	};

	struct Texture
	{
		unsigned int ID;
		TextureType Type;
		Texture(const char* path, TextureType type);
	};
}