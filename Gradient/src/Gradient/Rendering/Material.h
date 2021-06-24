#pragma once

#include "Gradient/Math/Math.h"

namespace Gradient
{
	struct Material
	{
		Vector3 Ambient;
		Vector3 Diffuse;
		Vector3 Specular;

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