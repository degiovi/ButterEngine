#pragma once

#include <memory>

#include "ButterEngine/Core/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Butter
{
	class BUTTER_API Log
	{

	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}

	private:

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};

}

#define BTR_CORE_TRACE(...)		::Butter::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define BTR_CORE_INFO(...)		::Butter::Log::GetCoreLogger()->info(__VA_ARGS__);
#define BTR_CORE_WARN(...)		::Butter::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define BTR_CORE_ERROR(...)		::Butter::Log::GetCoreLogger()->error(__VA_ARGS__);
#define BTR_CORE_CRITICAL(...)	::Butter::Log::GetCoreLogger()->critical(__VA_ARGS__);

#define BTR_TRACE(...)			::Butter::Log::GetClientLogger()->trace(__VA_ARGS__);
#define BTR_INFO(...)			::Butter::Log::GetClientLogger()->info(__VA_ARGS__);
#define BTR_WARN(...)			::Butter::Log::GetClientLogger()->warn(__VA_ARGS__);
#define BTR_ERROR(...)			::Butter::Log::GetClientLogger()->error(__VA_ARGS__);
#define BTR_CRITICAL(...)		::Butter::Log::GetClientLogger()->critical(__VA_ARGS__);
