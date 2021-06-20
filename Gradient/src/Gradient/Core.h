#pragma once

#ifdef GD_PLATFORM_WINDOWS
	#ifdef GD_BUILD_DLL
		#define GD_API __declspec(dllexport)
		#define ASSERT(x) if (!(x)) __debugbreak()
	#else
		#define GD_API __declspec(dllimport)
	#endif
#else
	#ifdef GD_BUILD_SO
		#define GD_API __attribute__(visibility("default"))
	#else
		#define GD_API
	#endif
#endif

#define GLCALL(x) glClearError();\
    x;\
    ASSERT(glLogCall(#x, __FILE__, __LINE__))

#define GD_BIND_EVENT_CALLBACK(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

void glClearError();

bool glLogCall(const char* function, const char* file, const int line);