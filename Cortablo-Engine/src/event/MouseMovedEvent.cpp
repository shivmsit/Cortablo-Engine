#include "MouseMovedEvent.h"

MouseMovedEvent::MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y)
{

}

float MouseMovedEvent::GetX() const
{
	return m_MouseX;
}

float MouseMovedEvent::GetY() const
{
	return m_MouseY;
}

std::string MouseMovedEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
	return stringstream.str();
}
