// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../CortabloEngine.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <glm/glm.hpp>

#include "../sys/FileSystem.h"

class ObjModel
{
private:
	std::vector<float> m_Vertices;
	std::vector<float> m_UVs;
	std::vector<float> m_Normals;
	std::vector<unsigned int> m_Faces;
public:
	ObjModel(const std::string& filePath);
	~ObjModel();

	std::vector<float> GetVertices();
	std::vector<float> GetUVs();
	std::vector<float> GetNormals();
	std::vector<unsigned int> GetFaces();
};