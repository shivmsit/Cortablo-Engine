#pragma once

#include "MouseButtonEvent.h"

#include <sstream>

class MouseButtonPressedEvent : public MouseButtonEvent
{
public:
	MouseButtonPressedEvent(int button);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(MouseButtonPressed)
};
