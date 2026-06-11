//
// Created by lagdads on 2026/6/11.
// 窗口事件
//
module;

#include "FufuEngine.hpp"


export module FufuEngine.Event.ApplicationEvent;

import FufuEngine.Event;
import glm;

export namespace FufuEngine
{
	class WindowCloseEvent : public FufuEngine::Event {
		public:
			WindowCloseEvent() = default;

			EVENT_TYPE(WindowClose);
			EVENT_CATEGORY(EventCategoryApplication);

			auto ToString() const -> std::string override {
				return "WindowCloseEvent: Window closed";
			}
	};


	class WindowFocusEvent : public FufuEngine::Event {
		public:
			WindowFocusEvent() = default;

			EVENT_TYPE(WindowFocus);
			EVENT_CATEGORY(EventCategoryApplication);

			auto ToString() const -> std::string override {
				return "WindowFocusEvent: Window focused";
			}
	};

	class WindowLostFocusEvent : public FufuEngine::Event {
		public:
			WindowLostFocusEvent() = default;

			EVENT_TYPE(WindowLostFocus);
			EVENT_CATEGORY(EventCategoryApplication);

			auto ToString() const -> std::string override {
				return "WindowLostFocusEvent: Window lost focus";
			}
	};

	class WindowResizeEvent : public FufuEngine::Event {
		public:
			WindowResizeEvent() = default;

			explicit WindowResizeEvent(glm::vec2 size) :
				m_size(size) {
			}

			EVENT_TYPE(WindowResize);
			EVENT_CATEGORY(EventCategoryApplication);

			auto GetSize() const -> glm::vec2 {
				return m_size;
			}

			auto ToString() const -> std::string override {
				return std::format("WindowResizeEvent: Window resized to {}, {}", m_size.x, m_size.y);
			}

		private:
			glm::vec2 m_size{0.0F, 0.0F};
	};

	class AppUpdateEvent : public FufuEngine::Event {
		public:
			AppUpdateEvent() = default;

			EVENT_TYPE(AppUpdate);
			EVENT_CATEGORY(EventCategoryApplication);

			auto ToString() const -> std::string override {
				return "AppUpdateEvent: Application updated";
			}
	};

	class AppRenderEvent : public FufuEngine::Event {
		public:
			AppRenderEvent() = default;

			EVENT_TYPE(AppRender);
			EVENT_CATEGORY(EventCategoryApplication);

			auto ToString() const -> std::string override {
				return "AppRenderEvent: Application rendered";
			}
	};

	class AppTickEvent : public FufuEngine::Event {
		public:
			AppTickEvent() = default;

			EVENT_TYPE(AppTick);
			EVENT_CATEGORY(EventCategoryApplication);

			auto ToString() const -> std::string override {
				return "AppTickEvent: Application tick";
			}
	};

}
