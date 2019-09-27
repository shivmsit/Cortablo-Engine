#include "MouseScrolledEvent.h"

MouseScrolledEvent::MouseScrolledEvent(float xOffset, float yOffset) : m_XOffset(xOffset), m_YOffset(yOffset)
{

}

float MouseScrolledEvent::GetXOffset() const
{
	return m_XOffset;
}

float MouseScrolledEvent::GetYOffset() const
{
	return m_YOffset;
}

std::string MouseScrolledEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
	return stringstream.str();
}
