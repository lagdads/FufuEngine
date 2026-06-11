
// Created by lagdads on 2026/6/11.
// 日志
//
module;
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
module FufuEngine.Log;


namespace FufuEngine
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	auto Log::init() -> void {
		// 配置统一的日志输出格式。
		spdlog::set_pattern("%^[%T] %n: %v%$");

		// 创建核心日志器并启用追踪级别。
		s_CoreLogger = spdlog::stdout_color_mt("Core");
		s_CoreLogger->set_level(spdlog::level::trace);

		// 创建客户端日志器并启用追踪级别。
		s_ClientLogger = spdlog::stdout_color_mt("Client");
		s_ClientLogger->set_level(spdlog::level::trace);
	}


	auto Log::getCoreLogger() -> std::shared_ptr<spdlog::logger> {
		return s_CoreLogger;
	}

	auto Log::getClientLogger() -> std::shared_ptr<spdlog::logger> {
		return s_ClientLogger;
	}
}
