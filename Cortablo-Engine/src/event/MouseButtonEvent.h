#pragma once

#include "Event.h"

class MouseButtonEvent : public Event
{
public:
	int GetMouseButton() const;

	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
protected:
	MouseButtonEvent(int button);

	int m_Button;
};
