// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <glm/glm.hpp>
#include <glm/ext.hpp>

class OrthographicCamera
{
private:
	glm::mat4 m_ProjectionMatrix, m_ViewMatrix;

	glm::vec3 m_Position;
	float m_Rotation;
public:
	OrthographicCamera(float left, float right, float bottom, float top, const glm::vec3& position = glm::vec3(0.0f), float rotation = 0.0f);
	~OrthographicCamera();

	const glm::mat4& GetProjectionMatrix();
	const glm::mat4& GetViewMatrix();

	const glm::vec3& GetPosition();
	float GetRotation();

	void SetPosition(const glm::vec3& position);
	void SetRotation(float rotation);

	void Update();
};