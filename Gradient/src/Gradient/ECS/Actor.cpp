#include "Gradient/ECS/Actor.h"
#include "Gradient/ECS/Scene.h"
#include "Gradient/ECS/Handlers/CameraHandler.h"
#include "Gradient/ECS/Component.h"
#include "Gradient/Core/Log.h"

#include <algorithm>

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

			Handler* handler;
			switch (T)
			{
			case Component::OrthographicCamera:
				handler = new OrthographicCameraHandler(*this);
				break;
			case Component::PerspectiveCamera:
				handler = new PerspectiveCameraHandler(*this);
				break;
			default:
				handler = nullptr;
				break;
			}
			if (handler != nullptr)
				handler->OnInit();
				scene->handlers.emplace_back(handler);
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
		for (auto it : scene->handlers)
		{
			if (it->type == Handler::GetEnumFromType<T>() && it->owner == this)
			{
				it->OnDestroy();
				delete it;
				scene->handlers.erase(std::remove(scene->handlers.begin(), scene->handlers.end(), it), 
					scene->handlers.end());
			}
		}
	}

	template<typename T>
	void* Actor::GetComponent()
	{
		return (void*)scene->registry.get<T>(handle);
	}
}