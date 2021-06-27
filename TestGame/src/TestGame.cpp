#include <Gradient.h>

class TestGame : public Gradient::Application
{
public:
	TestGame()
	{
		window->Init(800, 600, "Test App");
	}

	~TestGame()
	{

	}
};

Gradient::Application* Gradient::CreateApplication()
{
	return new TestGame();
}