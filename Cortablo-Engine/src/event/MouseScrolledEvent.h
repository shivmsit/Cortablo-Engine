#pragma once

#include "Event.h"

#include <sstream>

class MouseScrolledEvent : public Event
{
private:
	float m_XOffset, m_YOffset;
public:
	MouseScrolledEvent(float xOffset, float yOffset);

	float GetXOffset() const;
	float GetYOffset() const;

	std::string ToString() const override;

	EVENT_CLASS_TYPE(MouseScrolled)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
};
