#include <Gradient.h>
#include <Gradient/Entry.h>

#include "GameScope.h"

class TestGame : public Gradient::Application
{
public:
	TestGame()
	{
		window->Init(800, 600, "Test App");
		scopeStack->PushBack(new GameScope());
	}

	~TestGame()
	{

	}
};

Gradient::Application* Gradient::CreateApplication()
{
	return new TestGame();
}