#include "MouseButtonReleasedEvent.h"

MouseButtonReleasedEvent::MouseButtonReleasedEvent(int button) : MouseButtonEvent(button)
{

}

std::string MouseButtonReleasedEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "MouseButtonReleased: " << m_Button;
	return stringstream.str();
}
