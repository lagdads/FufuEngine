import FufuEngine;
import FufuEngine.EntryPoint;
import std;

namespace Sandbox
{
	class SandboxApp : public FufuEngine::Application {
		public:
			SandboxApp() = default;

			~SandboxApp() override = default;
	};
}

namespace FufuEngine
{
	auto CreateApplication() -> std::unique_ptr<Application> {
		return std::make_unique<Sandbox::SandboxApp>();
	}
}
