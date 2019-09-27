#include "EventDispatcher.h"

EventDispatcher::EventDispatcher(Event& event) : m_Event(event)
{

}

template<typename T, typename F>
bool EventDispatcher::Dispatch(const F& func)
{
	if (m_Event.GetEventType() == T::GetStaticType())
	{
		m_Event.Handled = func(static_cast<T&>(m_Event));
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& ostream, const Event& event)
{
	return ostream << event.ToString();
}