// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top, const glm::vec3& position, float rotation)
{
	m_ProjectionMatrix = glm::ortho(left, right, bottom, top, 1.0f, -1.0f);
	printf("[Camera] (%s) (Left: %f, Right: %f, Bottom: %f, Top: %f)\n", __FUNCTION__, left, right, bottom, top);

	SetPosition(position);
	printf("[Camera] (%s) Position changed! (X: %f, Y: %f, Z: %f)\n", __FUNCTION__, position.x, position.y, position.z);

	SetRotation(rotation);
	printf("[Camera] (%s) Rotation changed! (Z: %f)\n", __FUNCTION__, rotation);
}

OrthographicCamera::~OrthographicCamera()
{

}

const glm::mat4& OrthographicCamera::GetProjectionMatrix()
{
	return m_ProjectionMatrix;
}

const glm::mat4& OrthographicCamera::GetViewMatrix()
{
	return m_ViewMatrix;
}

const glm::vec3& OrthographicCamera::GetPosition()
{
	return m_Position;
}

float OrthographicCamera::GetRotation()
{
	return m_Rotation;
}

void OrthographicCamera::SetPosition(const glm::vec3& position)
{
	m_Position = position;

	m_ViewMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	m_ViewMatrix = glm::translate(m_ViewMatrix, m_Position);
}

void OrthographicCamera::SetRotation(float rotation)
{
	m_Rotation = rotation;

	m_ViewMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), glm::vec3(0.0f, 0.0f, 1.0f));
	m_ViewMatrix = glm::translate(m_ViewMatrix, m_Position);
}

void OrthographicCamera::Update()
{

}
