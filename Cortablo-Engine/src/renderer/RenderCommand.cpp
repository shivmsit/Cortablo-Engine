// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "RenderCommand.h"

#if RENDER_API == RENDERAPI_OPENGL
#include "../platform/opengl/OpenGLRenderCommand.h"
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX

#endif

RenderCommand* RenderCommand::Init()
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLRenderCommand();
#elif RENDER_API == RENDERAPI_VULKAN
	return nullptr;
#elif RENDER_API == RENDERAPI_DIRECTX
	return nullptr;
#endif
}
