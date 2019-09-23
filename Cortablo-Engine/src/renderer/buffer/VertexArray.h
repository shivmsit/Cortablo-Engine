// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../../CortabloEngine.h"

class VertexArray
{
public:
	static VertexArray* Init();
	virtual ~VertexArray() = default;

	virtual void Bind() = 0;
	virtual void Unbind() = 0;
};