#pragma once

#include "Gradient/Math/Math.h"
#include "Gradient/Rendering/Texture.h"

namespace Gradient
{
	struct Material
	{
		Texture Diffuse;
		Texture Specular;

		float Shininess;
	};

	struct Light
	{
		Vector3 Ambient;
		Vector3 Diffuse;
		Vector3 Specular;

		Vector3 Position;
	};
}