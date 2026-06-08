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

extern "C++" auto FufuEngine::CreateApplication() -> std::unique_ptr<Application> {
	return std::make_unique<Sandbox::SandboxApp>();
}
