#pragma once


#include "Chemy\Core.h"
#include "spdlog/spdlog.h"

namespace Chemy {
	
	class CHEMY_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}


// Core log macros
#define CZ_CORE_TRACE(...)    ::Chemy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CZ_CORE_INFO(...)     ::Chemy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CZ_CORE_WARN(...)     ::Chemy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CZ_CORE_ERROR(...)    ::Chemy::Log::GetCoreLogger()->error(__VA_ARGS__)

// Client log macros
#define CZ_TRACE(...)	      ::Chemy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CZ_INFO(...)	      ::Chemy::Log::GetClientLogger()->info(__VA_ARGS__)
#define CZ_WARN(...)	      ::Chemy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CZ_ERROR(...)	      ::Chemy::Log::GetClientLogger()->error(__VA_ARGS__)
