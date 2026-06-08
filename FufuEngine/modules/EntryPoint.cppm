//
// Created by lagdads li on 2026/6/8.
//

export module FufuEngine.EntryPoint;

import FufuEngine.Application;
import std;

export extern "C++" {
	namespace FufuEngine
	{
		std::unique_ptr<Application> CreateApplication();
	}
}

// 使用 extend “c++” 让该函数不属于该模块
extern "C++" auto main(int argc, char** argv) -> int {
	auto app = FufuEngine::CreateApplication();
	app->Run();
	return 0;
}
