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
			unsigned int face[9] = { };

			sscanf_s(line.substr(2).c_str(), "%d/%d/%d %d/%d/%d %d/%d/%d\n", &face[0], &face[1], &face[2], &face[3], &face[4], &face[5], &face[6], &face[7], &face[8]);

			m_Faces.push_back(face[0]);
			m_Faces.push_back(face[1]);
			m_Faces.push_back(face[2]);
			m_Faces.push_back(face[3]);
			m_Faces.push_back(face[4]);
			m_Faces.push_back(face[5]);
			m_Faces.push_back(face[6]);
			m_Faces.push_back(face[7]);
			m_Faces.push_back(face[8]);
		}
	}
	printf("[Model] (%s) Model loaded!\n", __FUNCTION__);
	printf("[Model] (%s) -> File: %s\n", __FUNCTION__, filePath.c_str());
	printf("[Model] (%s) -> Vertices: %d\n", __FUNCTION__, m_Vertices.size());
	printf("[Model] (%s) -> UVs: %d\n", __FUNCTION__, m_UVs.size());
	printf("[Model] (%s) -> Normals: %d\n", __FUNCTION__, m_Normals.size());
	printf("[Model] (%s) -> Faces: %d\n", __FUNCTION__, m_Faces.size());

	if (m_Vertices.empty())
	{
		printf("[Model] (%s) This model has no vertices!\n", __FUNCTION__);
		return;
	}
	if (m_UVs.empty())
	{
		printf("[Model] (%s) This model has no UVs!\n", __FUNCTION__);
		return;
	}
	if (m_Normals.empty())
	{
		printf("[Model] (%s) This model has no Normals!\n", __FUNCTION__);
		return;
	}
	if (m_Faces.empty())
	{
		printf("[Model] (%s) This model has no Faces!\n", __FUNCTION__);
		return;
	}
}

ObjModel::~ObjModel()
{
	m_Vertices.clear();
	m_UVs.clear();
	m_Normals.clear();
	m_Faces.clear();
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

std::vector<unsigned int> ObjModel::GetFaces()
{
	return m_Faces;
}
