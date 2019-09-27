#include "KeyEvent.h"

KeyEvent::KeyEvent(int keycode) : m_KeyCode(keycode)
{

}

int KeyEvent::GetKeyCode() const
{
	return m_KeyCode;
}
