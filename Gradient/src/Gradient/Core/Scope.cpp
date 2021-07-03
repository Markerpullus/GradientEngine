#include "Gradient/Core/Scope.h"

namespace Gradient
{

	ScopeStack::~ScopeStack()
	{
		for (auto scope : stack)
		{
			scope->OnDetach();
			delete scope;
		}
	}

	void ScopeStack::PushFront(Scope* scope)
	{
		stack.emplace(stack.begin(), scope);
		scope->OnAttach();
	}

	void ScopeStack::PushBack(Scope* scope)
	{
		stack.emplace_back(scope);
		scope->OnAttach();
	}

	void ScopeStack::PopFront()
	{
		Scope* scope = stack.front();
		stack.erase(stack.begin());
		scope->OnDetach();
	}

	void ScopeStack::PopBack()
	{
		Scope* scope = stack.back();
		stack.pop_back();
		scope->OnDetach();
	}

}