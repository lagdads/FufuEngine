//
// Created by lagdads on 2026/6/11.
// 鼠标事件
//
module;

#include "FufuEngine.hpp"

export module FufuEngine.Event.MouseEvent;

import FufuEngine.Event;
import glm;

export namespace FufuEngine
{
	class MouseMovedEvent : public FufuEngine::Event {
		public:
			EVENT_TYPE(MouseMoved);
			EVENT_CATEGORY(EventCategoryInput | EventCategoryMouse);

			MouseMovedEvent(glm::vec2 position) :
				m_position(position) {
			}

			auto GetMovedPosition() const -> glm::vec2 {
				return m_position;
			}

			auto ToString() const -> std::string override {
				return std::format("MouseMovedEvent: {}, {}", m_position.x, m_position.y);
			}

		private:
			glm::vec2 const m_position;

	};

	/**大多数情况下，只有y轴有offset*/
	class MouseScrolledEvent : public FufuEngine::Event {
		public:
			EVENT_TYPE(MouseScrolled);
			EVENT_CATEGORY(EventCategoryInput | EventCategoryMouse);

			MouseScrolledEvent(glm::vec2 offset) :
				m_offset(offset) {
			}

			auto GetScrolledOffset() const -> glm::vec2 {
				return m_offset;
			}

			auto ToString() const -> std::string override {
				return std::format("MouseScrolledEvent: {}, {}", m_offset.x, m_offset.y);
			}

		private:
			glm::vec2 const m_offset;
	};

	class MouseButtonEvent : public FufuEngine::Event {
		public:
			EVENT_CATEGORY(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton);

			auto GetKeyCode() const -> int {
				return m_keyCode;
			}

		protected:
			int m_keyCode;

			MouseButtonEvent(const int keyCode) :
				m_keyCode(keyCode) {
			}

	};

	class MousePressedEvent : public MouseButtonEvent {
		public:
			EVENT_TYPE(MouseButtonPressed);

			MousePressedEvent(const int keyCode, const int repeatCount) :
				MouseButtonEvent(keyCode),
				m_repeatCount(repeatCount) {
			}

			auto GetRepeatCount() const -> int {
				return m_repeatCount;
			}

			auto ToString() const -> std::string override {
				return std::format("MouseButtonPressedEvent: {}, repeatCount: {}", m_keyCode, m_repeatCount);
			}

		protected:
			int m_repeatCount;


	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {
		public:
			EVENT_TYPE(MouseButtonReleased);

			MouseButtonReleasedEvent(const int keyCode) :
				MouseButtonEvent(keyCode) {
			}

			auto ToString() const -> std::string override {
				return std::format("MouseButtonReleasedEvent: {}", m_keyCode);
			}

	};
}
