#include "Gradient/Core/Scopes/Scope.h"

namespace Gradient
{

	ScopeStack::~ScopeStack()
	{
		for (auto scope : stack)
		{
			scope->OnDetech();
			delete scope;
		}
	}

	void ScopeStack::PushFront(Scope* scope)
	{
		stack.insert(stack.begin(), scope);
		scope->OnAttach();
	}

	void ScopeStack::PushBack(Scope* scope)
	{
		stack.push_back(scope);
		scope->OnAttach();
	}

	void ScopeStack::PopFront()
	{
		Scope* scope = stack.front();
		stack.erase(stack.begin());
		scope->OnDetech();
	}

	void ScopeStack::PopBack()
	{
		Scope* scope = stack.back();
		stack.pop_back();
		scope->OnDetech();
	}

}