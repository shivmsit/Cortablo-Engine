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
	std::vector<glm::vec3> m_Vertices = { };
	std::vector<glm::vec2> m_UVs = { };
	std::vector<glm::vec3> m_Normals = { };

	std::vector<unsigned int> m_VertexIndices = { };
	std::vector<unsigned int> m_UVIndices = { };
	std::vector<unsigned int> m_NormalIndices = { };
public:
	ObjModel(const std::string& filePath);
	~ObjModel();

	std::vector<glm::vec3> GetVertices();
	std::vector<glm::vec2> GetUVs();
	std::vector<glm::vec3> GetNormals();
	
	std::vector<unsigned int> GetVertexIndices();
	std::vector<unsigned int> GetUVIndices();
	std::vector<unsigned int> GetNormalIndices();
};