// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../../CortabloEngine.h"
#include <iostream>

class VertexBuffer
{
public:
	static VertexBuffer* Init(float* vertices, uint32_t size);
	virtual ~VertexBuffer() = default;

	virtual void Bind() = 0;
	virtual void Unbind() = 0;
};
