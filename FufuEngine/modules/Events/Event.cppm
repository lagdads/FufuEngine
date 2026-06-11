//
// Created by lagdads li on 2026/6/9.
//

module;

#include <FufuEngine/Core/Macros.hpp>

export module FufuEngine.Event;

import std;

export namespace FufuEngine
{
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, WindowFocusGained,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};


	enum EventCategory {
		EventCategoryNone = 0,

		EventCategoryInput       = BIT(0),
		EventCategoryApplication = BIT(1),
		EventCategoryKeyboard    = BIT(2),
		EventCategoryMouse       = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

	/**
	 * 事件
	 */
	class FUFU_API Event {
		public:
			virtual ~Event() = default;

			virtual EventType GetEventType() const = 0;

			virtual std::string_view GetName() const = 0;

			virtual int GetCategoryFlags() const = 0;

			virtual std::string_view ToString() const {
				return GetName();
			}

			virtual bool IsInCategory(EventCategory category) const {
				return GetCategoryFlags() & category;
			}

		protected:
			bool m_handled = false;
	};
}
