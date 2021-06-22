#pragma once

#include "Gradient/Core.h"
#include "Gradient/EventSystem/Event.h"
#include "Gradient/EventSystem/MouseCodes.h"

namespace Gradient
{
	class MouseUpEvent : public Event
	{
	public:
		MouseCode mouseCode;

		MouseUpEvent(MouseCode m)
			: Event(EventName::MouseUp, EventType::MouseEvent), mouseCode(m)
		{ }
	};

	class MouseDownEvent : public Event
	{
	public:
		MouseCode mouseCode;

		MouseDownEvent(MouseCode m)
			: Event(EventName::MouseDown, EventType::MouseEvent), mouseCode(m)
		{ }
	};

	class MouseScrolledEvent : public Event
	{
	public:
		double xOffset, yOffset;

		MouseScrolledEvent(double x, double y)
			: Event(EventName::MouseScrolled, EventType::MouseEvent), xOffset(x), yOffset(y)
		{ }
	};

	class MouseMovedEvent : public Event
	{
	public:
		double xPos, yPos;

		MouseMovedEvent(double x, double y)
			: Event(EventName::MouseMoved, EventType::MouseEvent), xPos(x), yPos(y)
		{ }
	};

	class MouseEnterWindowEvent : public Event
	{
	public:
		MouseEnterWindowEvent()
			: Event(EventName::MouseEnterWindow, EventType::MouseEvent)
		{ }
	};

	class MouseLeaveWindowEvent : public Event
	{
	public:
		MouseLeaveWindowEvent()
			: Event(EventName::MouseLeaveWindow, EventType::MouseEvent)
		{ }
	};
}