// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLContext.h"

OpenGLContext::OpenGLContext(SDL_Window* window) : m_Window(window)
{
	if (!m_Window)
	{
		printf("[Context] (%s) Error: m_SDLWindow is null!\n", __FUNCTION__);
		__debugbreak();
	}
	else
	{
		m_OpenGLContext = SDL_GL_CreateContext(m_Window);
		if (!m_OpenGLContext)
		{
			printf("[Context] (%s) Error: Context could not be initialized!\n", __FUNCTION__);
			printf("[Context] (%s) -> %s\n", __FUNCTION__, SDL_GetError());
			__debugbreak();
		}
		else
		{
			printf("[Context] (%s) Context initialized!\n", __FUNCTION__);
			printf("[Context] (%s) -> GL_VENDOR: %s\n", __FUNCTION__, glGetString(GL_VENDOR));
			printf("[Context] (%s) -> GL_RENDERER: %s\n", __FUNCTION__, glGetString(GL_RENDERER));
			printf("[Context] (%s) -> GL_VERSION: %s\n", __FUNCTION__, glGetString(GL_VERSION));
			printf("[Context] (%s) -> GL_SHADING_LANGUAGE_VERSION: %s\n", __FUNCTION__, glGetString(GL_SHADING_LANGUAGE_VERSION));
		}
	}
}

OpenGLContext::~OpenGLContext()
{

}

void OpenGLContext::SwapBuffers()
{
	SDL_GL_SwapWindow(m_Window);
}

void OpenGLContext::Shutdown()
{
	SDL_GL_DeleteContext(m_OpenGLContext);
}