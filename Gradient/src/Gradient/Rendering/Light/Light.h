#pragma once

#include "Gradient/Core.h"
#include "Gradient/Math/Math.h"

namespace Gradient
{
	enum class LightType
	{
		PointLight,
		DirectionalLight,
		FlashLight
	};

	class GD_API Light
	{
	public:
		LightType type;
		
		Vector3 ambient;
		Vector3 diffuse;
		Vector3 specular;

		Light(LightType t, Vector3 a, Vector3 d, Vector3 s)
			: type(t), ambient(a), diffuse(d), specular(s)
		{ }
	};
}