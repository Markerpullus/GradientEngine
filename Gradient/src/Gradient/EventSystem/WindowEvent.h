#pragma once

#include "Gradient/Core.h"
#include "Gradient/EventSystem/Event.h"

#include <stdint.h>

namespace Gradient
{
	class WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent()
			: Event(EventName::WindowClose, EventType::WindowEvent)
		{ }
	};

	class WindowResizeEvent : public Event
	{
	public:
		int32_t width, height;

		WindowResizeEvent(int w, int h)
			: Event(EventName::WindowResize, EventType::WindowEvent), width(w), height(h)
		{ }
	};
}