// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <glm/glm.hpp>

#include "../CortabloEngine.h"

class RenderCommand
{
private:

public:
	static RenderCommand* Init();
	virtual ~RenderCommand() = default;

	virtual void SetClearColor(const glm::vec4& color) = 0;
	virtual void Clear() = 0;
	virtual void SetRenderMode(unsigned int mode) = 0;
};