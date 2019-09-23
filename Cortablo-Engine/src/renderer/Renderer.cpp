// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Renderer.h"

#if RENDER_API == RENDERAPI_OPENGL
#include "../platform/opengl/OpenGLRenderer.h"
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX

#endif

Renderer* Renderer::Init(Shader* shader)
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLRenderer(shader);
#elif RENDER_API == RENDERAPI_VULKAN
	return nullptr;
#elif RENDER_API == RENDERAPI_DIRECTX
	return nullptr;
#endif
}
