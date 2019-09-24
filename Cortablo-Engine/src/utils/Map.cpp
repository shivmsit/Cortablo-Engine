// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Map.h"

Map::Map(const std::string& filePath)
{
	m_JsonFile = new JsonFile(filePath);

	m_MapName = m_JsonFile->GetJsonValue()["mapName"].asString();
	m_MapCategory = m_JsonFile->GetJsonValue()["mapCategory"].asString();

	for (unsigned int i = 0; i < m_JsonFile->GetJsonValue()["gameObjects"].size(); i++)
	{
		m_GameObjects.push_back(new GameObject(
			glm::vec3(
				m_JsonFile->GetJsonValue()["gameObjects"][i]["position"][0].asFloat(),
				m_JsonFile->GetJsonValue()["gameObjects"][i]["position"][1].asFloat(),
				m_JsonFile->GetJsonValue()["gameObjects"][i]["position"][2].asFloat()),
			glm::vec3(
				m_JsonFile->GetJsonValue()["gameObjects"][i]["rotation"][0].asFloat(),
				m_JsonFile->GetJsonValue()["gameObjects"][i]["rotation"][1].asFloat(),
				m_JsonFile->GetJsonValue()["gameObjects"][i]["rotation"][2].asFloat()),
			glm::vec3(
				m_JsonFile->GetJsonValue()["gameObjects"][i]["scale"][0].asFloat(),
				m_JsonFile->GetJsonValue()["gameObjects"][i]["scale"][1].asFloat(),
				m_JsonFile->GetJsonValue()["gameObjects"][i]["scale"][2].asFloat()),
			Texture::Init(GL_NEAREST, m_JsonFile->GetJsonValue()["gameObjects"][i]["texture"].asString()),
			new ObjModel(m_JsonFile->GetJsonValue()["gameObjects"][i]["model"].asString())));
	}
}

Map::~Map()
{
	m_GameObjects.clear();
}

const std::string& Map::GetMapName()
{
	return m_MapName;
}

const std::string& Map::GetMapCategory()
{
	return m_MapCategory;
}

std::vector<GameObject*> Map::GetGameObjects()
{
	return m_GameObjects;
}
