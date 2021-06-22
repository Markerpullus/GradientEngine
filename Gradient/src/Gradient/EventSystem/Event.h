#pragma once

#include "Gradient/Core.h"

namespace Gradient
{
	enum class EventName
	{
		None = 0,
		MouseDown, MouseUp, MouseMoved, MouseScrolled, MouseEnterWindow, MouseLeaveWindow,
		KeyUp, KeyDown, KeyRepeat, KeyTyped,
		WindowClose, WindowResize
	};

	enum class EventType
	{
		None = 0,
		MouseEvent,
		KeyEvent,
		WindowEvent
	};

	class Event
	{
	public:
		Event(EventName n, EventType t)
			:name(n), type(t)
		{ }

		EventName name;

		EventType type;

		virtual inline EventName GetName() { return name; } // Useless function just to satisfy the conditions for dynamic casting

		virtual inline EventType GetType() { return type; }
	};
}