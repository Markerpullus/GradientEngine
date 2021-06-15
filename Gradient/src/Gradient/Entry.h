#pragma once

#ifdef GD_PLATFORM_WINDOWS

extern Gradient::Application* Gradient::CreateApplication();

int main(int argc, char** argv)
{
	Gradient::Log::init();
	GD_CORE_INFO("Initialized Log!");

	auto app = Gradient::CreateApplication();
	app->run();
	delete app;
}

#endif