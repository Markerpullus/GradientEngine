#pragma once

#include "Gradient/Math/Math.h"

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
		unsigned int id;
		TextureType Type;

		Texture(const char* path, TextureType type);

		Texture(int width, int height, Vector3 color, TextureType type);
	};
}