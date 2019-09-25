// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Texture.h"

#if RENDER_API == RENDERAPI_OPENGL
#include "../platform/opengl/OpenGLTexture.h"
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX
#endif

Texture* Texture::Init(const std::string& filePath)
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLTexture(filePath);
#elif RENDER_API == RENDERAPI_VULKAN
	return nullptr;
#elif RENDER_API == RENDERAPI_DIRECTX
	return nullptr;
#endif
}

Texture* Texture::Init(int width, int height, void* data)
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLTexture(width, height, data);
#elif RENDER_API == RENDERAPI_VULKAN
	return nullptr;
#elif RENDER_API == RENDERAPI_DIRECTX
	return nullptr;
#endif

}

Texture* Texture::Init(std::vector<std::string> filePaths)
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLTexture(filePaths);
#endif

}
