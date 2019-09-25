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
	GLuint m_VertexBufferID;
public:
	OpenGLVertexBuffer(uint32_t size, void* data);
	~OpenGLVertexBuffer();

	void AddSubData(uint32_t offset, uint32_t size, void* data) override;

	void Bind() override;
	void Unbind() override;
};