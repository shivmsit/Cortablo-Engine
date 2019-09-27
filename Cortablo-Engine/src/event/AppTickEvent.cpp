#include "AppTickEvent.h"

AppTickEvent::AppTickEvent()
{

}

std::string AppTickEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "AppTickEvent!";
	return stringstream.str();
}
