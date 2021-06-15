#include <Gradient.h>

class Sandbox : public Gradient::Application
{
public:
	Sandbox()
	{
		window->Init(800, 600, "Test App");
	}

	~Sandbox()
	{

	}
};

Gradient::Application* Gradient::CreateApplication()
{
	return new Sandbox();
}