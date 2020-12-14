#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace HazmatEngine 
{
	class HAZMAT_ENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;  }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define HM_CORE_ERROR(...) ::HazmatEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HM_CORE_WARN(...) ::HazmatEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HM_CORE_TRACE(...) ::HazmatEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HM_CORE_INFO(...) ::HazmatEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HM_CORE_FATAL(...) ::HazmatEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define HM_ERROR(...) ::HazmatEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define HM_WARN(...) ::HazmatEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HM_TRACE(...) ::HazmatEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HM_INFO(...) ::HazmatEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define HM_FATAL(...) ::HazmatEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)