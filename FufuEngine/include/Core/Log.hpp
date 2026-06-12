//
// Created by lagdads li on 2026/6/8.
//

#pragma once

#include <spdlog/spdlog.h>

#define FUFU_CORE_TRACE(...) ::FufuEngine::Log::getCoreLogger()->trace(__VA_ARGS__)
#define FUFU_CORE_INFO(...) ::FufuEngine::Log::getCoreLogger()->info(__VA_ARGS__)
#define FUFU_CORE_WARN(...) ::FufuEngine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define FUFU_CORE_ERROR(...) ::FufuEngine::Log::getCoreLogger()->error(__VA_ARGS__)
#define FUFU_CORE_CRITICAL(...) ::FufuEngine::Log::getCoreLogger()->critical(__VA_ARGS__)

#define FUFU_CLIENT_TRACE(...) ::FufuEngine::Log::getClientLogger()->trace(__VA_ARGS__)
#define FUFU_CLIENT_INFO(...) ::FufuEngine::Log::getClientLogger()->info(__VA_ARGS__)
#define FUFU_CLIENT_WARN(...) ::FufuEngine::Log::getClientLogger()->warn(__VA_ARGS__)
#define FUFU_CLIENT_ERROR(...) ::FufuEngine::Log::getClientLogger()->error(__VA_ARGS__)
#define FUFU_CLIENT_CRITICAL(...) ::FufuEngine::Log::getClientLogger()->critical(__VA_ARGS__)


