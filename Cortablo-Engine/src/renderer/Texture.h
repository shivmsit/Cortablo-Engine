// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../CortabloEngine.h"

#include <iostream>

#include "Font.h"

class Texture
{
public:
	static Texture* Init(const std::string& filePath);
	static Texture* Init(int width, int height, void* data);
	static Texture* Init(std::vector<std::string> filePaths);
	virtual ~Texture() = default;

	virtual void Bind(unsigned int slot = 0) = 0;
	virtual void Unbind() = 0;

	virtual int GetWidth() = 0;
	virtual int GetHeight() = 0;
	virtual int GetBPP() = 0;
	virtual unsigned char* GetPixels() = 0;
};
