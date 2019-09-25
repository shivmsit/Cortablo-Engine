// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../../renderer/Texture.h"

#include <iostream>

class OpenGLTexture : public Texture
{
private:
	uint32_t m_TextureID;

	std::string m_TextureFilePath;
	int m_TextureWidth, m_TextureHeight, m_TextureBPP;

	unsigned char* m_TextureBuffer;

	GLenum m_TextureTarget;
public:
	OpenGLTexture(const std::string& filePath);
	OpenGLTexture(int width, int height, void* data);
	OpenGLTexture(std::vector<std::string> filePaths);
	~OpenGLTexture();

	void Bind(unsigned int slot = 0) override;
	void Unbind() override;

	int GetWidth() override;
	int GetHeight() override;
	int GetBPP() override;
	unsigned char* GetPixels() override;
};
