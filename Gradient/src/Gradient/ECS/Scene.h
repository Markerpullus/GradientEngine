#pragma once

#include "Gradient/Core.h"
#include "entt/entity/registry.hpp"

namespace Gradient
{
	class GD_API Actor;

	class GD_API Scene
	{
	private:
		entt::registry registry;

		int index;

		Scene(int i);

	public:
		
		~Scene();

		Actor& CreateActor();

		void DestroyActor(Actor& actor);

		void OnUpdate();

		friend class SceneManager;
		friend class Actor;
		friend class Handler;
	};
}
