// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Context.h"

#if RENDER_API == RENDERAPI_OPENGL
#include "../platform/opengl/OpenGLContext.h"
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX

#endif

Context* Context::Init(SDL_Window* window)
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLContext(window);
#elif RENDER_API == RENDERAPI_VULKAN
	return nullptr;
#elif RENDER_API == RENDERAPI_DIRECTX
	return nullptr;
#endif
}
