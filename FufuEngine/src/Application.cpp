//
// Created by lagdads li on 2026/6/8.
//

module FufuEngine.Application;

import std;

namespace FufuEngine
{
	Application::Application() = default;

	Application::~Application() = default;

	void Application::Run() {
		std::printf("FufuEngine application running\n");
		while (true);
	}
}
