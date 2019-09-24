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
			float vertex[3] = { };

			sscanf_s(line.substr(2).c_str(), "%f %f %f\n", &vertex[0], &vertex[1], &vertex[2]);

			m_Vertices.push_back(vertex[0]);
			m_Vertices.push_back(vertex[1]);
			m_Vertices.push_back(vertex[2]);
		}
		else if (line.substr(0, 3) == "vt ")
		{
			float uv[2] = { };

			sscanf_s(line.substr(2).c_str(), "%f %f\n", &uv[0], &uv[1]);

			m_UVs.push_back(uv[0]);
			m_UVs.push_back(uv[1]);
		}
		else if (line.substr(0, 3) == "vn ")
		{
			float normal[3] = { };

			sscanf_s(line.substr(2).c_str(), "%f %f %f\n", &normal[0], &normal[1], &normal[2]);

			m_Normals.push_back(normal[0]);
			m_Normals.push_back(normal[1]);
			m_Normals.push_back(normal[2]);
		}
		else if (line.substr(0, 2) == "f ")
		{
			unsigned int vertexIndex[3] = { };
			unsigned int uvIndex[3] = { };
			unsigned int normalIndex[3] = { };

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

std::vector<float> ObjModel::GetVertices()
{
	return m_Vertices;
}

std::vector<float> ObjModel::GetUVs()
{
	return m_UVs;
}

std::vector<float> ObjModel::GetNormals()
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

