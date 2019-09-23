// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Font.h"

Font::Font(const std::string& filePath, int fontSize) : m_FilePath(filePath), m_FontSize(fontSize)
{

}

Font::~Font()
{

}

const std::string& Font::GetFilePath() const
{
	return m_FilePath;
}

int Font::GetSize() const
{
	return m_FontSize;
}