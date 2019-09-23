// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <iostream>
#include <vector>

#include "../renderer/GameObject.h"
#include "JsonFile.h"

class Map
{
private:
	std::string m_MapName, m_MapCategory;

	std::vector<GameObject*> m_GameObjects;

	JsonFile* m_JsonFile;
public:
	Map(const std::string& filePath);
	~Map();

	const std::string& GetMapName();
	const std::string& GetMapCategory();

	std::vector<GameObject*> GetGameObjects();
};