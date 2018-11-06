#pragma once

#ifdef CHEMY_PLATFORM_WINDOWS
	#ifdef CHEMY_BUILD_DLL
		#define CHEMY_API __declspec(dllexport)
	#else
	#define CHEMY_API __declspec(dllimport)
#endif
#else
#error Chemy only supports Windows!
#endif
