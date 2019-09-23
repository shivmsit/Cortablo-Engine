// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLContext.h"

OpenGLContext::OpenGLContext(SDL_Window* window) : m_Window(window)
{
	if (!m_Window)
	{
		printf("[OpenGL] Error: m_SDLWindow is null!\n");
	}
	else
	{
		m_OpenGLContext = SDL_GL_CreateContext(m_Window);
		if (!m_OpenGLContext)
		{
			printf("[OpenGL] Error: Context could not be initialized!\n");
			printf("[OpenGL] -> %s\n", SDL_GetError());
		}
		else
		{
			printf("[OpenGL] Context initialized!\n");
			printf("[OpenGL] -> GL_VENDOR: %s\n", glGetString(GL_VENDOR));
			printf("[OpenGL] -> GL_RENDERER: %s\n", glGetString(GL_RENDERER));
			printf("[OpenGL] -> GL_VERSION: %s\n", glGetString(GL_VERSION));
			printf("[OpenGL] -> GL_SHADING_LANGUAGE_VERSION: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
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