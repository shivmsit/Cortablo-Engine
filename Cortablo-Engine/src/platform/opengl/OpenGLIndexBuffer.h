// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../../renderer/buffer/IndexBuffer.h"

#include <GL/glew.h>
#include <iostream>

class OpenGLIndexBuffer : public IndexBuffer
{
private:
	unsigned int m_IndexBufferID;
public:
	OpenGLIndexBuffer(uint32_t* indices, uint32_t size);
	~OpenGLIndexBuffer();

	void Bind() override;
	void Unbind() override;
};
