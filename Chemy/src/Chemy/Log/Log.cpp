#pragma once

#include "czpch.h"
#include "Log.h"
#include "spdlog\sinks\stdout_color_sinks.h"

namespace Chemy {


	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("CHEMY");
		s_CoreLogger->set_level(spdlog::level::trace);


		s_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		s_CoreLogger->set_level(spdlog::level::trace);

	}

}