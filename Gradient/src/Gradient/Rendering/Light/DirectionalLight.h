#pragma once

#include "Gradient/Rendering/Light/Light.h"

namespace Gradient
{
	class GD_API DirectionalLight : public Light
	{
	public:
		Vector3 direction;

		DirectionalLight(Vector3 a, Vector3 d, Vector3 s, Vector3 dir)
			: Light(LightType::PointLight, a, d, s), direction(dir)
		{ }
	};
}