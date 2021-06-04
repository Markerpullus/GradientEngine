#include <Gradient.h>

class Sandbox : public Gradient::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox()
	{

	}
};

Gradient::Application* Gradient::createApplication()
{
	return new Sandbox();
}