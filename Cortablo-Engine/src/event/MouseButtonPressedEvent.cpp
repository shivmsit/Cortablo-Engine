#include "MouseButtonPressedEvent.h"

MouseButtonPressedEvent::MouseButtonPressedEvent(int button) : MouseButtonEvent(button)
{

}

std::string MouseButtonPressedEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "MouseButtonPressedEvent: " << m_Button;
	return stringstream.str();
}
