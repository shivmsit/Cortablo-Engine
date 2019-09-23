// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../CortabloEngine.h"

#include <iostream>
#include <fstream>
#include <json/json.h>

class JsonFile
{
private:
	std::ifstream m_JsonFile;
	Json::Value m_JsonValue;
	std::string m_JsonErrors;
	Json::CharReaderBuilder m_JsonCharReaderBuilder;
public:
	JsonFile(const std::string& filePath);
	~JsonFile();

	const Json::Value& GetJsonValue();
};
