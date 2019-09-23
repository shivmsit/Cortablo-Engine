// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <SDL2/SDL.h>
#include "../CortabloEngine.h"

class Context
{
public:
	static Context* Init(SDL_Window* window);
	virtual ~Context() = default;

	virtual void SwapBuffers() = 0;
	virtual void Shutdown() = 0;
};