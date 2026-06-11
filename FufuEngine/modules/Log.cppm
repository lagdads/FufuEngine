module;

#include <FufuEngine.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

export module FufuEngine.Log;

import std;

export namespace FufuEngine
{
	class FUFU_API Log {
		public:
			/**
			 * 初始化核心日志器和客户端日志器。
			 */
			static void init();

			/**
			 * 获取核心日志器。
			 * @return 核心日志器的共享指针。
			 */
			static auto getCoreLogger() -> std::shared_ptr<spdlog::logger>;

			/**
			 * 获取客户端日志器。
			 * @return 客户端日志器的共享指针。
			 */
			static auto getClientLogger() -> std::shared_ptr<spdlog::logger>;

		private:
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
