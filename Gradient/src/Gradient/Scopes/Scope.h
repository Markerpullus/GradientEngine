#pragma once

#include "Gradient/EventSystem/Event.h"

#include <vector>

namespace Gradient
{
	class Scope
	{
	private:
		char* name;

	public:
		Scope(char* n)
			: name(n)
		{ }

		virtual void OnAttach();

		virtual void OnDetech();

		virtual void OnEvent(Event& e);

		virtual void OnUpdate();
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
