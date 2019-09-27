#pragma once

#include "KeyEvent.h"

#include <sstream>

class KeyReleasedEvent : public KeyEvent
{
	KeyReleasedEvent(int keycode);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(KeyReleased)
};
