#pragma once

#include "Gradient/Core.h"
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

	struct GD_API Texture
	{
		unsigned int id;
		TextureType type;

		Texture(const char* path, TextureType type);

		Texture(int width, int height, Vector3 color, TextureType type);
	};
}