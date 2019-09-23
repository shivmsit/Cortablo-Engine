// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLTexture.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>

OpenGLTexture::OpenGLTexture(int filter, const std::string& filePath)
{
	stbi_set_flip_vertically_on_load(1);

	m_TextureBuffer = stbi_load(filePath.c_str(), &m_TextureWidth, &m_TextureHeight, &m_TextureBPP, 0);

	GLenum internalFormat = 0, format = 0;
	if (m_TextureBPP == 4)
	{
		internalFormat = GL_RGBA8;
		format = GL_RGBA;
	}
	else if (m_TextureBPP == 3)
	{
		internalFormat = GL_RGB8;
		format = GL_RGB;
	}

	glGenTextures(1, &m_TextureID);
	Bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, m_TextureWidth, m_TextureHeight, 0, format, GL_UNSIGNED_BYTE, m_TextureBuffer);
	glBindTexture(GL_TEXTURE_2D, NULL);

	if (m_TextureBuffer)
		stbi_image_free(m_TextureBuffer);
}

OpenGLTexture::OpenGLTexture(int filter, int width, int height, void* data)
{
	glGenTextures(1, &m_TextureID);
	Bind();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, (GLsizei)width, (GLsizei)height, 0, GL_RED, GL_UNSIGNED_BYTE, data);

	glBindTexture(GL_TEXTURE_2D, NULL);
}

OpenGLTexture::OpenGLTexture(const std::string& filePath)
{
	m_TextureBuffer = stbi_load(filePath.c_str(), &m_TextureWidth, &m_TextureHeight, &m_TextureBPP, 0);
}

OpenGLTexture::~OpenGLTexture()
{
	if (m_TextureBuffer)
		stbi_image_free(m_TextureBuffer);

	Unbind();
	glDeleteTextures(1, &m_TextureID);
}

void OpenGLTexture::Bind(unsigned int slot)
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

void OpenGLTexture::Unbind()
{
	glBindTexture(GL_TEXTURE_2D, NULL);
}

int OpenGLTexture::GetWidth()
{
	return m_TextureWidth;
}

int OpenGLTexture::GetHeight()
{
	return m_TextureHeight;
}

int OpenGLTexture::GetBPP()
{
	return m_TextureBPP;
}

unsigned char* OpenGLTexture::GetPixels()
{
	return m_TextureBuffer;
}
