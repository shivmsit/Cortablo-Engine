// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../../renderer/buffer/VertexBuffer.h"

#include <iostream>
#include <GL/glew.h>

class OpenGLVertexBuffer : public VertexBuffer
{
private:
	uint32_t m_VertexBufferID;
public:
	OpenGLVertexBuffer(float* vertices, uint32_t size);
	~OpenGLVertexBuffer();

	void Bind() override;
	void Unbind() override;
};