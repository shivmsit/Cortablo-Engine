// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <iostream>
#include <GL/glew.h>

#include "../../renderer/buffer/VertexArray.h"

class OpenGLVertexArray : public VertexArray
{
private:
	uint32_t m_VertexArrayID;
public:
	OpenGLVertexArray();
	~OpenGLVertexArray();

	void Bind() override;
	void Unbind() override;
};