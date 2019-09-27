#include "WindowResizeEvent.h"

WindowResizeEvent::WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height)
{

}

unsigned int WindowResizeEvent::GetWidth() const
{
	return m_Width;
}

unsigned int WindowResizeEvent::GetHeight() const
{
	return m_Height;
}

std::string WindowResizeEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "WindowResizeEvent: " << m_Width << ", " << m_Height;
	return stringstream.str();
}
