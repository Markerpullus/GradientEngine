#pragma once

#include "Gradient/Core.h"
#include "Gradient/ECS/Handlers/Handler.h"
#include "entt/entity/registry.hpp"

#include <vector>

namespace Gradient
{
	class GD_API Actor;

	class GD_API Scene
	{
	private:
		entt::registry registry;

		int index;

		Scene(int i);

		std::vector<Handler*> handlers;

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
