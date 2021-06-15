#pragma once

#include "Gradient/Core.h"

namespace Gradient
{
	enum eventName
	{
		None = 0,
		MouseDown, MouseUp, MouseMove, MouseDrag, MouseScrolled,
		KeyUp, KeyDown, KeyRepeat,
		MouseEnterWindow, MouseLeaveWindow, WindowResize
	};

	enum eventType
	{
		None = 0,
		MouseEvent,
		KeyEvent,
		WindowEvent
	};

	class GD_API Event
	{
	public:
		inline eventName GetEventName() { return name; };

		inline eventType GetEventType() { return type; };

		Event(eventName n, eventType t)
			:name(n), type(t)
		{
		}

	private:
		eventName name;

		eventType type;
	};
}