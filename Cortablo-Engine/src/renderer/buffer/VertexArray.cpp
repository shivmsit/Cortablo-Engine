// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "VertexArray.h"

#if RENDER_API == RENDERAPI_OPENGL
#include "../../platform/opengl/OpenGLVertexArray.h"
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX

#endif

VertexArray* VertexArray::Init()
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLVertexArray();
#elif RENDER_API == RENDERAPI_VULKAN
	return nullptr;
#elif RENDER_API == RENDERAPI_DIRECTX
	return nullptr;
#endif
}
