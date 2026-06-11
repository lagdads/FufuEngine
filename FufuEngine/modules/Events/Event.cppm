//
// Created by lagdads li on 2026/6/9.
// 事件
//

module;

#include "FufuEngine.hpp"

export module FufuEngine.Event;

import std;

export namespace FufuEngine
{
	/**
	 * @brief 事件类型
	 *
	 * 可用值: None=0, WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
	 * WindowFocusGained, AppTick, AppUpdate, AppRender, KeyPressed, KeyReleased,
	 * MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	 */
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	/**
	 * @brief 事件分类
	 *
	 * 可用值: EventCategoryNone=0, EventCategoryInput=BIT(0), EventCategoryApplication=BIT(1),
	 * EventCategoryKeyboard=BIT(2), EventCategoryMouse=BIT(3), EventCategoryMouseButton=BIT(4)
	 */
	enum EventCategory {
		EventCategoryNone = 0,

		EventCategoryInput       = BIT(0),
		EventCategoryApplication = BIT(1),
		EventCategoryKeyboard    = BIT(2),
		EventCategoryMouse       = BIT(3),
		EventCategoryMouseButton = BIT(4),
	};

	class FUFU_API Event {

		public:
			virtual ~Event() = default;

			virtual auto GetEventType() const -> EventType {
				return EventType::None;
			}

			virtual auto GetName() const -> std::string_view = 0;

			virtual auto GetCategoryFlags() const -> int {
				return EventCategoryNone;
			}

			virtual auto ToString() const -> std::string {
				return std::string(GetName());
			}

			auto IsInCategory(EventCategory category) const -> bool {
				return (GetCategoryFlags() & category) != 0;
			}

			bool Handled = false;

		protected:

	};


	// 接受一个事件引用，判断事件类型是否匹配，若匹配则调用回调函数
	class EventDispatcher {
		friend class Event;

		public:
			EventDispatcher(Event& event) :
				m_Event(event) {
			}

			template <typename T, typename F>
			bool Dispatch(const F& func) {
				if (m_Event.GetEventType() == T::GetStaticType())
				{
					m_Event.Handled = func(static_cast<T&>(m_Event)) || m_Event.Handled;
					return true;
				}
				return false;
			}

		private:
			Event& m_Event;
	};

}
