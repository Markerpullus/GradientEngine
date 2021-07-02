#pragma once

#ifdef GD_PLATFORM_WINDOWS

extern Gradient::Application* Gradient::CreateApplication();

int main(int argc, char** argv)
{
	Gradient::Log::init();

	auto app = Gradient::CreateApplication();
	app->Run();
	delete app;
}

#endif