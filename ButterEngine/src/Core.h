#pragma once

#ifdef BTR_PLATFORM_WINDOWS
	#ifdef BTR_BUILD_DLL
		#define BUTTER_API __declspec(dllexport)
	#else
		#define BUTTER_API __declspec(dllimport)
	#endif
#endif
