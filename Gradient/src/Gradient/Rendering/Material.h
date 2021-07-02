#pragma once

#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Texture.h"

namespace Gradient
{
	struct Material
	{
		Texture diffuse;
		Texture specular;

		float shininess;
	};
}