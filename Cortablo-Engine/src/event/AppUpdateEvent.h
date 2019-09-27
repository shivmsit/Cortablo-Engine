#pragma once

#include "Event.h"

#include <sstream>

class AppUpdateEvent : public Event
{
public:
	AppUpdateEvent();

	std::string ToString() const override;

	EVENT_CLASS_TYPE(AppUpdate)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
