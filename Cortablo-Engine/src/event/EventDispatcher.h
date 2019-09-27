#pragma once

#include <iostream>

#include "Event.h"

class EventDispatcher
{
private:
	Event& m_Event;
public:
	EventDispatcher(Event& event);

	template<typename T, typename F>
	bool Dispatch(const F& func);

	friend std::ostream& operator<<(std::ostream& ostream, const Event& event);
};