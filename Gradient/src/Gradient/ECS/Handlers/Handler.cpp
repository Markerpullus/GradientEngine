#include "Gradient/ECS/Handlers/Handler.h"
#include "Gradient/ECS/Component.h"

namespace Gradient
{
	template <typename T>
	HandlerType Handler::GetEnumFromType()
	{
		switch (T)
		{
		case Components::OrthographicCamera:
			return HandlerType::OrthographicCamera;
			break;
		case Components::PerspectiveCamera:
			return HandlerType::PerspectiveCamera;
			break;
		default:
			return HandlerType::None;
		}
	}
}