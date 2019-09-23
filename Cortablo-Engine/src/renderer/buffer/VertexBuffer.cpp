// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "VertexBuffer.h"

#if RENDER_API == RENDERAPI_OPENGL
#include "../../platform/opengl/OpenGLVertexBuffer.h"
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX

#endif

VertexBuffer* VertexBuffer::Init(float* vertices, uint32_t size)
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLVertexBuffer(vertices, size);
#elif RENDER_API == RENDERAPI_VULKAN
	return nullptr;
#elif RENDER_API == RENDERAPI_DIRECTX
	return nullptr;
#endif
}
