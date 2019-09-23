// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLIndexBuffer.h"

OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* indices, uint32_t size)
{
	glGenBuffers(1, &m_IndexBufferID);
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
	Unbind();
	glDeleteBuffers(1, &m_IndexBufferID);
}

void OpenGLIndexBuffer::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBufferID);
}

void OpenGLIndexBuffer::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
}
