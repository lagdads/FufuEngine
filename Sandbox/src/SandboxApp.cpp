#include <FufuEngine.hpp>

import FufuEngine;
import FufuEngine.EntryPoint;
import glm;
import std;

namespace Sandbox
{
	class SandboxApp : public FufuEngine::Application {
		public:
			SandboxApp() = default;

			~SandboxApp() override = default;

			void Run() override {
				// 初始化日志
				FufuEngine::Log::init();
				FUFU_CLIENT_INFO("Sandbox start");

				// 创建场景原点向量
				[[maybe_unused]] const glm::vec3 origin{0.0F};

				while (true);

			}
	};
}

namespace FufuEngine
{
	auto CreateApplication() -> std::unique_ptr<Application> {
		return std::make_unique<Sandbox::SandboxApp>();
	}
}
