// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Shader.h"

#if RENDER_API == RENDERAPI_OPENGL
#include "../platform/opengl/OpenGLShader.h"
#elif RENDER_API == RENDERAPI_VULKAN

#elif RENDER_API == RENDERAPI_DIRECTX

#endif

Shader* Shader::Init(const std::string& vertexFilePath, const std::string& fragmentFilePath)
{
#if RENDER_API == RENDERAPI_OPENGL
	return new OpenGLShader(vertexFilePath, fragmentFilePath);
#elif RENDER_API == RENDERAPI_VULKAN
	return nullptr;
#elif RENDER_API == RENDERAPI_DIRECTX
	return nullptr;
#endif
}

