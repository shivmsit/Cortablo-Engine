// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLVertexBuffer.h"

OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size)
{
	glGenBuffers(1, &m_VertexBufferID);
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	Unbind();
	glDeleteBuffers(1, &m_VertexBufferID);
}

void OpenGLVertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
}

void OpenGLVertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, NULL);
}
