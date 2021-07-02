#pragma once

#include "Gradient/Core.h"
#include "entt/entt.hpp"

namespace Gradient
{
	class GD_API Scene
	{
	private:
		entt::registry registry;

		int index;

	public:
		Scene() {}
		~Scene() = default;
	};
}
