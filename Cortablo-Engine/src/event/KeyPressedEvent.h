#pragma once

#include "KeyEvent.h"

#include <sstream>

class KeyPressedEvent : public KeyEvent
{
private:
	int m_RepeatCount;
public:
	KeyPressedEvent(int keycode, int repeatCount);

	int GetRepeatCount() const;

	std::string ToString() const override;

	EVENT_CLASS_TYPE(KeyPressed)
};