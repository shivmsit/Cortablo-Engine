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
	std::vector<float> m_Vertices = { };
	std::vector<float> m_UVs = { };
	std::vector<float> m_Normals = { };
	std::vector<unsigned int> m_VertexIndices = { };
	std::vector<unsigned int> m_UVIndices = { };
	std::vector<unsigned int> m_NormalIndices = { };
public:
	ObjModel(const std::string& filePath);
	~ObjModel();

	std::vector<float> GetVertices();
	std::vector<float> GetUVs();
	std::vector<float> GetNormals();
	std::vector<unsigned int> GetVertexIndices();
	std::vector<unsigned int> GetUVIndices();
	std::vector<unsigned int> GetNormalIndices();
};