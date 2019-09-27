#pragma once

#include "MouseButtonEvent.h"

#include <sstream>

class MouseButtonReleasedEvent : public MouseButtonEvent
{
public:
	MouseButtonReleasedEvent(int button);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(MouseButtonReleased)
};
