// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <iostream>

#include "../../CortabloEngine.h"

class IndexBuffer
{
public:
	static IndexBuffer* Init(uint32_t* indices, uint32_t size);
	virtual ~IndexBuffer() = default;

	virtual void Bind() = 0;
	virtual void Unbind() = 0;
};