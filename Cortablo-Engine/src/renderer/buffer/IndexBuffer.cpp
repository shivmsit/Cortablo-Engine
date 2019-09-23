// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "IndexBuffer.h"

#if RENDER_API == RENDERAPI_OPENGL
#include "../../platform/opengl/OpenGLIndexBuffer.h"
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX

#endif

IndexBuffer* IndexBuffer::Init(uint32_t* indices, uint32_t size)
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLIndexBuffer(indices, size);
#elif RENDER_API == RENDERAPI_VULKAN
	return nullptr;
#elif RENDER_API == RENDERAPI_DIRECTX
	return nullptr;
#endif
}
