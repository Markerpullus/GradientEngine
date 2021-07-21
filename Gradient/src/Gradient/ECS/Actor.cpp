#include "Gradient/ECS/Actor.h"
#include "Gradient/Core/Log.h"

namespace Gradient
{
	template<typename T>
	void Actor::AddComponent(T componenet)
	{
		entt::registry& registry = scene->registry;
		if (!registry.has<component>(handle))
		{
			auto& comp = registry.emplace<T>(handle);
			comp = component;
		}
		else
		{
			GD_CORE_WARN("Actor already has component");
		}
	}

	template<typename T>
	void Actor::RemoveComponent()
	{
		scene->registry.remove<T>(handle);
	}

	template<typename T>
	T& Actor::GetComponent()
	{
		return scene->registry.get<T>(handle);
	}
}