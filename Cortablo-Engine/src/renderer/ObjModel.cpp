// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "ObjModel.h"

ObjModel::ObjModel(const std::string& filePath)
{
	std::ifstream in(filePath.c_str(), std::ios::in);
	std::string line;

	while (std::getline(in, line))
	{
		if (line.substr(0, 2) == "v ")
		{
			glm::vec3 vertex;
			sscanf_s(line.substr(2).c_str(), "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z);
			m_Vertices.push_back(vertex);
		}
		else if (line.substr(0, 3) == "vt ")
		{
			glm::vec2 uv;
			sscanf_s(line.substr(2).c_str(), "%f %f\n", &uv.x, &uv.y);
			m_UVs.push_back(uv);
		}
		else if (line.substr(0, 3) == "vn ")
		{
			glm::vec3 normal;
			sscanf_s(line.substr(2).c_str(), "%f %f %f\n", &normal.x, &normal.y, &normal.z);
			m_Normals.push_back(normal);
		}
		else if (line.substr(0, 2) == "f ")
		{
			unsigned int vertexIndex[3];
			unsigned int uvIndex[3];
			unsigned int normalIndex[3];

			if (sscanf_s(line.substr(2).c_str(), "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2]) == 9);
			else if (sscanf_s(line.substr(2).c_str(), "%d %d %d\n", &vertexIndex[0], &vertexIndex[1], &vertexIndex[2]) == 3);
			else if (sscanf_s(line.substr(2).c_str(), "%d//%d %d//%d %d//%d\n", &vertexIndex[0], &normalIndex[0], &vertexIndex[1], &normalIndex[1], &vertexIndex[2], &normalIndex[2]));
			else printf("[Model] (%s) Error: Format not supported!\n", __FUNCTION__);

			for (unsigned int i = 0; i < 3; i++)
			{
				vertexIndex[i]--;
				uvIndex[i]--;
				normalIndex[i]--;

				m_VertexIndices.push_back(vertexIndex[i]);
				m_UVIndices.push_back(uvIndex[i]);
				m_NormalIndices.push_back(normalIndex[i]);
			}
		}
	}
	printf("[Model] (%s) Model loaded!\n", __FUNCTION__);
	printf("[Model] (%s) -> File: %s\n", __FUNCTION__, filePath.c_str());
	printf("[Model] (%s) -> Vertices: %d\n", __FUNCTION__, m_Vertices.size());
	printf("[Model] (%s) -> UVs: %d\n", __FUNCTION__, m_UVs.size());
	printf("[Model] (%s) -> Normals: %d\n", __FUNCTION__, m_Normals.size());
	printf("[Model] (%s) -> Vertex-Indices: %d\n", __FUNCTION__, m_VertexIndices.size());
	printf("[Model] (%s) -> UV-Indices: %d\n", __FUNCTION__, m_UVIndices.size());
	printf("[Model] (%s) -> Normal-Indices: %d\n", __FUNCTION__, m_NormalIndices.size());

	if (m_Vertices.empty())
		printf("[Model] (%s) This model has no vertices!\n", __FUNCTION__);
	if (m_UVs.empty())
		printf("[Model] (%s) This model has no UVs!\n", __FUNCTION__);
	if (m_Normals.empty())
		printf("[Model] (%s) This model has no Normals!\n", __FUNCTION__);
	if (m_VertexIndices.empty())
		printf("[Model] (%s) This model has no vertex indices!\n", __FUNCTION__);
	if (m_UVIndices.empty())
		printf("[Model] (%s) This model has no uv indices!\n", __FUNCTION__);
	if (m_NormalIndices.empty())
		printf("[Model] (%s) This model has no normal indices!\n", __FUNCTION__);
}

ObjModel::~ObjModel()
{
	m_Vertices.clear();
	m_UVs.clear();
	m_Normals.clear();

	m_VertexIndices.clear();
	m_UVIndices.clear();
	m_NormalIndices.clear();
}

std::vector<glm::vec3> ObjModel::GetVertices()
{
	return m_Vertices;
}

std::vector<glm::vec2> ObjModel::GetUVs()
{
	return m_UVs;
}

std::vector<glm::vec3> ObjModel::GetNormals()
{
	return m_Normals;
}

std::vector<unsigned int> ObjModel::GetVertexIndices()
{
	return m_VertexIndices;
}

std::vector<unsigned int> ObjModel::GetUVIndices()
{
	return m_UVIndices;
}

std::vector<unsigned int> ObjModel::GetNormalIndices()
{
	return m_NormalIndices;
}

