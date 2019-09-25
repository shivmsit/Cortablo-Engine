// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLVertexBuffer.h"

OpenGLVertexBuffer::OpenGLVertexBuffer(uint32_t size, void* data)
{
	glGenBuffers(1, &m_VertexBufferID);
	Bind();

	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
	Unbind();

	glDeleteBuffers(1, &m_VertexBufferID);
}

void OpenGLVertexBuffer::AddSubData(uint32_t offset, uint32_t size, void* data)
{
	Bind();

	glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}

void OpenGLVertexBuffer::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, m_VertexBufferID);
}

void OpenGLVertexBuffer::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, NULL);
}
