#pragma once

#include "Gradient/EventSystem/Event.h"

#include <string>
#include <vector>

namespace Gradient
{
	class GD_API Scope
	{
	protected:
		std::string name;

	public:
		Scope(const std::string& n)
			: name(n)
		{ }

		virtual void OnAttach() = 0;

		virtual void OnDetach() = 0;

		virtual void OnEvent(Event& e) = 0;

		virtual void OnUpdate() = 0;
	};

	class GD_API ScopeStack
	{
	private:
		std::vector<Scope*> stack;

	public:
		ScopeStack() { }
		~ScopeStack();

		std::vector<Scope*>::iterator begin() { return stack.begin(); }

		std::vector<Scope*>::iterator end() { return stack.end(); }

		void PushFront(Scope* scope);

		void PushBack(Scope* scope);

		void PopFront();

		void PopBack();
	};
}
