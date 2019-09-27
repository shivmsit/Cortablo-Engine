#pragma once

#include <sstream>

#include "Event.h"

class WindowResizeEvent : public Event
{
private:
	unsigned int m_Width, m_Height;
public:
	WindowResizeEvent(unsigned int width, unsigned int height);

	unsigned int GetWidth() const;
	unsigned int GetHeight() const;

	std::string ToString() const override;

	EVENT_CLASS_TYPE(WindowResize)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
