#pragma once

#include "Event.h"

#include <sstream>

class AppRenderEvent : public Event
{
	AppRenderEvent();

	std::string ToString() const override;

	EVENT_CLASS_TYPE(AppRender)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
