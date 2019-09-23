// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "FileSystem.h"

std::optional<std::string> FileSystem::ReadFile(const std::string& filePath)
{
	std::string result;
	std::ifstream stream(filePath);
	if (stream)
	{
		stream.seekg(0, std::ios::end);
		result.resize(stream.tellg());
		stream.seekg(0, std::ios::beg);
		stream.read(&result[0], result.size());
		stream.close();
		return result;
	}
	return {};
}