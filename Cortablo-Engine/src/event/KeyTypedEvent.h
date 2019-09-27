#pragma once

#include "KeyEvent.h"

#include <sstream>

class KeyTypedEvent : public KeyEvent
{
public:
	KeyTypedEvent(int keycode);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(KeyTyped)
};
