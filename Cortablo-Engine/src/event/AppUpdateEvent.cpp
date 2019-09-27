#include "AppUpdateEvent.h"

AppUpdateEvent::AppUpdateEvent()
{

}

std::string AppUpdateEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "AppUpdateEvent!";
	return stringstream.str();
}
