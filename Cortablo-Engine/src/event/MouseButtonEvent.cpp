#include "MouseButtonEvent.h"

MouseButtonEvent::MouseButtonEvent(int button) : m_Button(button)
{

}

int MouseButtonEvent::GetMouseButton() const
{
	return m_Button;
}
