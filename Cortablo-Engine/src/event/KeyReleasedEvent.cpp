#include "KeyReleasedEvent.h"

KeyReleasedEvent::KeyReleasedEvent(int keycode) : KeyEvent(keycode)
{

}

std::string KeyReleasedEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "KeyReleasedEvent: " << m_KeyCode;
	return stringstream.str();
}
