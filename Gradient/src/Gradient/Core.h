#pragma once

#ifdef GD_PLATFORM_WINDOWS
	#ifdef GD_BUILD_DLL
		#define GD_API __declspec(dllexport)
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