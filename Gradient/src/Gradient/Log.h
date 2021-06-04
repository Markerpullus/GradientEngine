#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Gradient
{
	class GD_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }

		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> coreLogger;

		static std::shared_ptr<spdlog::logger> clientLogger;

	};
}

// Core Log Macros
#define GD_CORE_INFO(...)        Gradient::Log::getCoreLogger()->info(__VA_ARGS__)
#define GD_CORE_ERROR(...)       Gradient::Log::getCoreLogger()->error(__VA_ARGS__)
#define GD_CORE_WARN(...)        Gradient::Log::getCoreLogger()->warn(__VA_ARGS__)
#define GD_CORE_TRACE(...)       Gradient::Log::getCoreLogger()->trace(__VA_ARGS__)
#define GD_CORE_CRITICAL(...)    Gradient::Log::getCoreLogger()->critical(__VA_ARGS__)

// Client Log Macros
#define GD_CLIENT_INFO(...)      Gradient::Log::getClientLogger()->info(__VA_ARGS__)
#define GD_CLIENT_ERROR(...)     Gradient::Log::getClientLogger()->error(__VA_ARGS__)
#define GD_CLIENT_WARN(...)      Gradient::Log::getClientLogger()->warn(__VA_ARGS__)
#define GD_CLIENT_TRACE(...)     Gradient::Log::getClientLogger()->trace(__VA_ARGS__)
#define GD_CLIENT_CRITICAL(...)  Gradient::Log::getClientLogger()->critical(__VA_ARGS__)