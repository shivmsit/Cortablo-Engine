#pragma once

#include "Event.h"

#include <sstream>

class WindowCloseEvent : public Event
{
public:
	WindowCloseEvent();

	std::string ToString() const override;

	EVENT_CLASS_TYPE(WindowClose)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
