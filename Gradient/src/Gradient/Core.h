#pragma once

#ifdef GD_PLATFORM_WINDOWS
	#ifdef GD_BUILD_DLL
		#define GD_API __declspec(dllexport)
	#else
		#define GD_API __declspec(dllimport)
	#endif
#else
	#error Windows only!
#endif