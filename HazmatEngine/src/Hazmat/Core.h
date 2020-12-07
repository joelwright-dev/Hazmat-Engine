#pragma once

#ifdef HM_PLATFORM_WINDOWS
	#ifdef HM_BUILD_DLL
		#define HAZMAT_ENGINE_API __declspec(dllexport)
	#else
		#define HAZMAT_ENGINE_API __declspec(dllimport)
	#endif
#else
	#error Hazmat Engine only supports Windows!
#endif