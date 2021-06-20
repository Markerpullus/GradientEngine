#pragma once

#include "Gradient/Core.h"
#include "Gradient/EventSystem/Event.h"
#include "Gradient/EventSystem/KeyCodes.h"

namespace Gradient
{
	class KeyDownEvent : public Event
	{
	public:
		KeyCode keyCode;

		KeyDownEvent(KeyCode c)
			: Event(EventName::KeyDown, EventType::KeyEvent), keyCode(c)
		{ }
	};

	class KeyUpEvent : public Event
	{
	public:
		KeyCode keyCode;

		KeyUpEvent(KeyCode c)
			: Event(EventName::KeyUp, EventType::KeyEvent), keyCode(c)
		{ }
	};

	class KeyRepeatEvent : public Event
	{
	public:
		KeyCode keyCode;

		KeyRepeatEvent(KeyCode c)
			: Event(EventName::KeyRepeat, EventType::KeyEvent), keyCode(c)
		{ }
	};

	class KeyTypedEvent : public Event
	{
	public:
		KeyCode keyCode;

		KeyTypedEvent(KeyCode c)
			: Event(EventName::KeyTyped, EventType::KeyEvent), keyCode(c)
		{ }
	};
}