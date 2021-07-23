#pragma once

#include "Gradient/ECS/Actor.h"

namespace Gradient
{
	enum class HandlerType
	{
		None = 0,
		OrthographicCamera,
		PerspectiveCamera,
		Model,
		Physics
	};

	class Handler
	{
	protected:
		Actor* owner;
		HandlerType type;

	public:
		Handler(HandlerType t, Actor* a)
			: type(t), owner(a)
		{ }
		~Handler() = default;

		virtual void OnInit() = 0;

		virtual void OnUpdate() = 0;

		virtual void OnDestroy() = 0;

		template <typename T>
		static HandlerType GetEnumFromType();

		friend class Scene;
		friend class Actor;
	};
}
