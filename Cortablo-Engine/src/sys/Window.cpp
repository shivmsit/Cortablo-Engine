// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Window.h"

#if RENDER_API == RENDERAPI_OPENGL
#include "../platform/opengl/OpenGLWindow.h"
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX
#include "../platform/win32/Win32Window.h"
#endif

Window* Window::Init(const std::string& title, int width, int height)
{
	CortabloEngine::EngineParameters::Set("windowTitle", title);
	CortabloEngine::EngineParameters::Set("windowWidth", width);
	CortabloEngine::EngineParameters::Set("windowHeight", height);

#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLWindow(title, width, height);
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX
	return new Win32Window(NULL, 1, title, width, height);
#endif
}
