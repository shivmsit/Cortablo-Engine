// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLVertexArray.h"

OpenGLVertexArray::OpenGLVertexArray()
{
	glGenVertexArrays(1, &m_VertexArrayID);
	Bind();
}

OpenGLVertexArray::~OpenGLVertexArray()
{
	glDeleteVertexArrays(1, &m_VertexArrayID);
}

void OpenGLVertexArray::Bind()
{
	glBindVertexArray(m_VertexArrayID);
}

void OpenGLVertexArray::Unbind()
{
	glBindVertexArray(NULL);
}
