// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../CortabloEngine.h"

#include <iostream>
#include <glm/glm.hpp>
#include <map>
#include <GL/glew.h>

struct Character
{
	unsigned int TextureID;
	glm::ivec2 Size;
	glm::ivec2 Bearing;
	unsigned int Advance;
};

class Font
{
private:
	std::string m_FilePath;
	int m_FontSize;
public:
	Font(const std::string& filePath, int fontSize);
	~Font();

	const std::string& GetFilePath() const;
	int GetSize() const;
};