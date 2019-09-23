// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/glew.h>

#include "../../renderer/Context.h"

class OpenGLContext : public Context
{
private:
	SDL_Window* m_Window;
	SDL_GLContext m_OpenGLContext;
public:
	OpenGLContext(SDL_Window* window);
	~OpenGLContext();

	void SwapBuffers() override;
	void Shutdown() override;
};
