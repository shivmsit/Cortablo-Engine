#include "WindowCloseEvent.h"

WindowCloseEvent::WindowCloseEvent()
{

}

std::string WindowCloseEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "WindowCloseEvent!";
	return stringstream.str();
}
