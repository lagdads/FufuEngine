//
// Created by lagdads li on 2026/6/9.
//
#pragma once


/**
 * @brief 事件类型宏，用于在事件子类中实现 GetStaticType()、GetEventType() 和 GetName()
 *
 * @param type EventType 枚举值，可用值:
 *   None=0, WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved, WindowFocusGained,
 *   AppTick, AppUpdate, AppRender, KeyPressed, KeyReleased,
 *   MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
 */
#define EVENT_TYPE(type) \
	static constexpr ::FufuEngine::EventType GetStaticType() { return ::FufuEngine::EventType::type; } \
	::FufuEngine::EventType GetEventType() const override { return GetStaticType(); } \
	std::string_view GetName() const override { return #type; }

/**
 * @brief 事件分类宏，用于在事件子类中实现 GetCategoryFlags()
 *
 * @param category EventCategory 枚举值，可用值:
 *   EventCategoryNone=0, EventCategoryInput=BIT(0), EventCategoryApplication=BIT(1),
 *   EventCategoryKeyboard=BIT(2), EventCategoryMouse=BIT(3), EventCategoryMouseButton=BIT(4)
 */
#define EVENT_CATEGORY(category) \
	int GetCategoryFlags() const override { return category; }
