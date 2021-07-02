#pragma once

#include "Gradient/EventSystem/Event.h"

#include <vector>

namespace Gradient
{
	class GD_API Scope
	{
	private:
		char* name;

	public:
		Scope(char* n)
			: name(n)
		{ }

		virtual void OnAttach() = 0;

		virtual void OnDetech() = 0;

		virtual void OnEvent(Event& e) = 0;

		virtual void OnUpdate() = 0;
	};

	class ScopeStack
	{
	private:
		std::vector<Scope*> stack;

	public:
		ScopeStack() { }
		~ScopeStack();

		void PushFront(Scope* scope);

		void PushBack(Scope* scope);

		void PopFront();

		void PopBack();
	};
}
