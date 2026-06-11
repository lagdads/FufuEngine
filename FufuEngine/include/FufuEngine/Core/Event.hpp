//
// Created by lagdads li on 2026/6/9.
//
#pragma once

#define EVENT_TYPE(type) \
	static constexpr ::FufuEngine::EventType GetStaticType() { return ::FufuEngine::EventType::type; } \
	::FufuEngine::EventType GetEventType() const override { return GetStaticType(); } \
	std::string_view GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
	int GetCategoryFlags() const override { return category; }
