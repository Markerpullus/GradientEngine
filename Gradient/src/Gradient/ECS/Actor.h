#pragma once

#include "Gradient/Core.h"
#include "entt/entity/registry.hpp"

namespace Gradient
{
	class GD_API Scene;

	class GD_API Actor
	{
	private:
		entt::entity handle;
		Scene* scene;

	public:
		Actor(const Actor& actor) = default;
		Actor(entt::entity h, Scene* s)
			: handle(h), scene(s)
		{ };
		~Actor() = default;

		template<typename T>
		void AddComponent(T component);

		template<typename T>
		void RemoveComponent();

		template<typename T>
		T& GetComponent();

		friend class Scene;
	};
}
