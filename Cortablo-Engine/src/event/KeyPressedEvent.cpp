#include "KeyPressedEvent.h"

KeyPressedEvent::KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), m_RepeatCount(repeatCount)
{

}

int KeyPressedEvent::GetRepeatCount() const
{
	return m_RepeatCount;
}

std::string KeyPressedEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
	return stringstream.str();
}
