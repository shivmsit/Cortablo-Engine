// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../../CortabloEngine.h"
#include <iostream>
#include <glm/glm.hpp>

class VertexBuffer
{
public:
	static VertexBuffer* Init(uint32_t size, void* data);
	virtual ~VertexBuffer() = default;

	virtual void AddSubData(uint32_t offset, uint32_t size, void* data) = 0;

	virtual void Bind() = 0;
	virtual void Unbind() = 0;
};
