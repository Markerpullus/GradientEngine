#pragma once

#include <memory>

#include "Gradient/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Gradient
{
	class GD_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;

		static std::shared_ptr<spdlog::logger> clientLogger;

	};
}

// Core Log Macros
#define GD_CORE_INFO(...)        Gradient::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GD_CORE_ERROR(...)       Gradient::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GD_CORE_WARN(...)        Gradient::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GD_CORE_TRACE(...)       Gradient::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GD_CORE_CRITICAL(...)    Gradient::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define GD_CLIENT_INFO(...)      Gradient::Log::GetClientLogger()->info(__VA_ARGS__)
#define GD_CLIENT_ERROR(...)     Gradient::Log::GetClientLogger()->error(__VA_ARGS__)
#define GD_CLIENT_WARN(...)      Gradient::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GD_CLIENT_TRACE(...)     Gradient::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GD_CLIENT_CRITICAL(...)  Gradient::Log::GetClientLogger()->critical(__VA_ARGS__)