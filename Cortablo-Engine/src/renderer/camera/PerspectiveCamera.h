// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../../sys/Input.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

class PerspectiveCamera
{
private:
	glm::mat4 m_ProjectionMatrix, m_ViewMatrix;

	glm::vec3 m_Position, m_Rotation;

	bool m_Move, m_Rotate, m_Look;
public:
	PerspectiveCamera(float fov, float aspectRatio, const glm::vec3& position = glm::vec3(0.0f), const glm::vec3& rotation = glm::vec3(0.0f));
	~PerspectiveCamera();

	const glm::mat4& GetProjectionMatrix();
	const glm::mat4& GetViewMatrix();

	const glm::vec3& GetPosition();
	const glm::vec3& GetRotation();

	void SetPosition(const glm::vec3& position);
	void SetRotation(const glm::vec3& rotation);

	void SetMove(bool move);
	void SetRotate(bool rotate);
	void SetLook(bool look);

	void Update();
};