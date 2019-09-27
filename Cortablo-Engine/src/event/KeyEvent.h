#pragma once

#include "Event.h"

class KeyEvent : public Event
{
public:
	int GetKeyCode() const;

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
protected:
	KeyEvent(int keycode);

	int m_KeyCode;
};
