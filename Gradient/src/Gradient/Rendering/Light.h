#pragma once

#include "Gradient/Core.h"
#include "Gradient/Math/Math.h"

namespace Gradient
{
	enum class LightType
	{
		PointLight,
		DirectionalLight,
		SpotLight
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

		// Dummy function for polymorphism to work
		inline virtual LightType GetType() { return type; }
	};

	class GD_API PointLight : public Light
	{
	public:
		Vector3 position;

		PointLight(Vector3 a, Vector3 d, Vector3 s, Vector3 p)
			: Light(LightType::PointLight, a, d, s), position(p)
		{ }
	};

	class GD_API DirectionalLight : public Light
	{
	public:
		Vector3 direction;

		DirectionalLight(Vector3 a, Vector3 d, Vector3 s, Vector3 dir)
			: Light(LightType::PointLight, a, d, s), direction(dir)
		{ }
	};
}