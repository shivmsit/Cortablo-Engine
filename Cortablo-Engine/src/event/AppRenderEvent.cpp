#include "AppRenderEvent.h"

AppRenderEvent::AppRenderEvent()
{

}

std::string AppRenderEvent::ToString() const
{
	std::stringstream stringstream;
	stringstream << "AppRenderEvent!";
	return stringstream.str();
}
