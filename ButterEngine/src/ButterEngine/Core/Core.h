#pragma once

#include <memory>
#include <vector>

#ifdef BTR_PLATFORM_WINDOWS
#if BTR_DYNAMIC_LINK
	#ifdef BTR_BUILD_DLL
		#define BUTTER_API __declspec(dllexport)
	#else
		#define BUTTER_API __declspec(dllimport)
	#endif
#else
	#define BUTTER_API
#endif
#else
	#error Butter only supports Windows.
#endif

#ifdef HZ_DEBUG
#define HZ_ENABLE_ASSERTS
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define BTR_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define BTR_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define BTR_ASSERT(x, ...)
	#define BTR_CORE_ASSERT(x, ...)
#endif


#define BIT(x) (1 << x)

#define BTR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)

namespace Butter
{
	
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using List = std::vector<T>;
	
	/*
	template<typename T, typename ... Args>

	constexpr List<T> CreateList(Args&& ... args)
	{
		return std::vector<T>(std::forward<Args>(args)...);
	}
	*/

}