#pragma once

#ifdef GD_PLATFORM_WINDOWS

extern Gradient::Application* Gradient::createApplication();

int main(int argc, char** argv)
{
	Gradient::Log::init();
	GD_CORE_INFO("Initialized Log!");
	GD_CORE_INFO("The value of a is: {0}", 5);

	auto app = Gradient::createApplication();
	app->run();
	delete app;
}

#endif