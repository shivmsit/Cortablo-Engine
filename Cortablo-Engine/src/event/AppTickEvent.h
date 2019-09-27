#pragma once

#include "Event.h"

#include <sstream>

class AppTickEvent : public Event
{
public:
	AppTickEvent();

	std::string ToString() const override;

	EVENT_CLASS_TYPE(AppTick)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
