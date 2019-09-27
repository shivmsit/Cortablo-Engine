#include "Event.h"

std::string Event::ToString() const
{
	return GetName();
}

bool Event::IsInCategory(EventCategory category)
{
	return GetCategoryFlags() & category;
}