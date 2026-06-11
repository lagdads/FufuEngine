//
// Created by lagdads li on 2026/6/8.
//

module;

#include "FufuEngine.hpp"

export module FufuEngine.Application;

export namespace FufuEngine
{
	class FUFU_API Application {
		public:
			Application();
			virtual ~Application();

			virtual void Run();
	};
}
