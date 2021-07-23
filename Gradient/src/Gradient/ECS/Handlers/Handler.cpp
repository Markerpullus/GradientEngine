#include "Gradient/ECS/Handlers/Handler.h"

namespace Gradient
{
	template <typename T>
	HandlerType Handler::GetEnumFromType()
	{
		switch (T)
		{
		case Component::OrthographicCamera:
			return HandlerType::OrthographicCamera;
			break;
		case Component::PerspectiveCamera:
			return HandlerType::PerspectiveCamera;
			break;
		default:
			return HandlerType::None;
		}
	}
}