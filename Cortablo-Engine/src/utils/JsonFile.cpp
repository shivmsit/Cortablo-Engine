// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "JsonFile.h"

JsonFile::JsonFile(const std::string& filePath)
{
	m_JsonFile = std::ifstream(filePath.c_str());

	if (Json::parseFromStream(m_JsonCharReaderBuilder, m_JsonFile, &m_JsonValue, &m_JsonErrors))
	{
		printf("[JSON] JSON file has no errors!\n");
	}
	else
	{
		printf("[JSON] Error: JSON file has errors!\n");
		printf("[JSON] %s\n", m_JsonErrors.c_str());
	}

	m_JsonFile.close();
}

JsonFile::~JsonFile()
{

}

const Json::Value& JsonFile::GetJsonValue()
{
	return m_JsonValue;
}
