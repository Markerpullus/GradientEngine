#pragma once

#include "Gradient/Rendering/Light/Light.h"

namespace Gradient
{
	class GD_API PointLight : public Light
	{
	public:
		Vector3 position;

		PointLight(Vector3 a, Vector3 d, Vector3 s, Vector3 p)
			: Light(LightType::PointLight, a, d, s), position(p)
		{ }
	};
}