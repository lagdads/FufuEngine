

// Created by lagdads on 2026/6/11.
// 键盘事件
//
module;

#include "FufuEngine.hpp"

export module FufuEngine.Event.KeyEvent;

import FufuEngine.Event;

export namespace FufuEngine
{
	class KeyEvent : public FufuEngine::Event {
		public:
			EVENT_CATEGORY(EventCategoryKeyboard | EventCategoryInput);


			auto GetKeyCode() const -> int {
				return m_keyCode;
			}

		protected:
			int m_keyCode;

			KeyEvent(const int keyCode) :
				m_keyCode(keyCode) {
			}

	};

	class KeyPressedEvent : public KeyEvent {
		public:
			EVENT_TYPE(KeyPressed);

			KeyPressedEvent(const int keyCode, const int repeatCount) :
				KeyEvent(keyCode),
				m_repeatCount(repeatCount) {
			}

			auto GetRepeatCount() const -> int {
				return m_repeatCount;
			}

			auto ToString() const -> std::string override {
				return std::format("KeyPressedEvent: {}, repeatCount: {}", m_keyCode, m_repeatCount);
			}

		protected:
			int m_repeatCount;


	};

	class KeyReleasedEvent : public KeyEvent {
		public:
			EVENT_TYPE(KeyReleased);

			KeyReleasedEvent(const int keyCode) :
				KeyEvent(keyCode) {
			}

			auto ToString() const -> std::string override {
				return std::format("KeyReleasedEvent: {}", m_keyCode);
			}

	};
}

