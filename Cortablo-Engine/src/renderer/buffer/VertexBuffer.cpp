// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "VertexBuffer.h"

#if RENDER_API == RENDERAPI_OPENGL
#include "../../platform/opengl/OpenGLVertexBuffer.h"
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX

#endif

VertexBuffer* VertexBuffer::Init(uint32_t size, void* data)
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLVertexBuffer(size, data);
#elif RENDER_API == RENDERAPI_VULKAN
	return nullptr;
#elif RENDER_API == RENDERAPI_DIRECTX
	return nullptr;
#endif
}
