module;

#include <FufuEngine/Core/Macros.hpp>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

export module FufuEngine.Log;

import std;

export namespace FufuEngine
{
	class Log {
		public:
			static inline void init() {
				spdlog::set_pattern("%^[%T] %n: %v%$");

				s_CoreLogger = spdlog::stdout_color_mt("Core");
				s_CoreLogger->set_level(spdlog::level::trace);

				s_ClientLogger = spdlog::stdout_color_mt("Client");
				s_ClientLogger->set_level(spdlog::level::trace);
			}

			static inline auto getCoreLogger() {
				return s_CoreLogger;
			}

			static inline auto getClientLogger() {
				return s_ClientLogger;
			}

		private:
			inline static std::shared_ptr<spdlog::logger> s_CoreLogger;
			inline static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
