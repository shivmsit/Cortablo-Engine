#pragma once

#include "Event.h"

#include <sstream>

class MouseMovedEvent : public Event
{
private:
	float m_MouseX, m_MouseY;
public:
	MouseMovedEvent(float x, float y);

	float GetX() const;
	float GetY() const;

	std::string ToString() const override;

	EVENT_CLASS_TYPE(MouseMoved)
	EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
};
