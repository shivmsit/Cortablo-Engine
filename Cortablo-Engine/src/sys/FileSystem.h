// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <iostream>
#include <fstream>
#include <optional>

struct FileSystem
{
	static std::optional<std::string> ReadFile(const std::string& filePath);
};