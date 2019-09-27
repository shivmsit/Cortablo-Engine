#include "KeyTypedEvent.h"

KeyTypedEvent::KeyTypedEvent(int keycode) : KeyEvent(keycode)
{

}

std::string KeyTypedEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "KeyTypedEvent: " << m_KeyCode;
	return stringstream.str();
}
