// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(float fov, float aspectRatio, const glm::vec3& position, const glm::vec3& rotation)
{
	m_ProjectionMatrix = glm::perspective(glm::radians(fov), aspectRatio, 1.0f, -1.0f);
	printf("[Camera] (Perspective) FoV: %f\n", fov);

	SetPosition(position);
	printf("[Camera] (Perspective) Position changed! (X: %f, Y: %f, Z: %f)\n", position.x, position.y, position.z);

	SetRotation(rotation);
	printf("[Camera] (Perspective) Rotation changed! (X: %f, Y: %f, Z: %f)\n", rotation.x, rotation.y, rotation.z);
}

PerspectiveCamera::~PerspectiveCamera()
{

}

const glm::mat4& PerspectiveCamera::GetProjectionMatrix()
{
	return m_ProjectionMatrix;
}

const glm::mat4& PerspectiveCamera::GetViewMatrix()
{
	return m_ViewMatrix;
}

const glm::vec3& PerspectiveCamera::GetPosition()
{
    return m_Position;
}

const glm::vec3& PerspectiveCamera::GetRotation()
{
    return m_Rotation;
}

void PerspectiveCamera::SetPosition(const glm::vec3& position)
{
	m_Position = position;

	m_ViewMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_ViewMatrix = glm::rotate(m_ViewMatrix, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_ViewMatrix = glm::translate(m_ViewMatrix, m_Position);
}

void PerspectiveCamera::SetRotation(const glm::vec3& rotation)
{
	m_Rotation = rotation;

	m_ViewMatrix = glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	m_ViewMatrix = glm::rotate(m_ViewMatrix, glm::radians(m_Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	m_ViewMatrix = glm::translate(m_ViewMatrix, m_Position);

	if (m_Rotation.y > 360.0f)
		m_Rotation.y = 0.0f;
	if (m_Rotation.y < -360.0f)
		m_Rotation.y = 0.0f;
	if (m_Rotation.x > 90.0f)
		m_Rotation.x = 90.0f;
	if (m_Rotation.x < -90.0f)
		m_Rotation.x = -90.0f;
}

void PerspectiveCamera::Update()
{
	if (Input::IsKeyPressed(SDL_SCANCODE_W))
		SetPosition(GetPosition() - glm::vec3(cos(glm::radians(GetRotation().y - 90.0f)) * 1.0f, 0.0f, sin(glm::radians(GetRotation().y - 90.0f)) * 1.0f));
	if (Input::IsKeyPressed(SDL_SCANCODE_S))
		SetPosition(GetPosition() + glm::vec3(cos(glm::radians(GetRotation().y - 90.0f)) * 1.0f, 0.0f, sin(glm::radians(GetRotation().y - 90.0f)) * 1.0f));
	if (Input::IsKeyPressed(SDL_SCANCODE_A))
		SetPosition(GetPosition() + glm::vec3(cos(glm::radians(GetRotation().y)) * 1.0f, 0.0f, sin(glm::radians(GetRotation().y)) * 1.0f));
	if (Input::IsKeyPressed(SDL_SCANCODE_D))
		SetPosition(GetPosition() - glm::vec3(cos(glm::radians(GetRotation().y)) * 1.0f, 0.0f, sin(glm::radians(GetRotation().y)) * 1.0f));
	if (Input::IsKeyPressed(SDL_SCANCODE_SPACE))
		SetPosition(GetPosition() + glm::vec3(0.0f, 1.0f, 0.0f));
	if (Input::IsKeyPressed(SDL_SCANCODE_C))
		SetPosition(GetPosition() - glm::vec3(0.0f, 1.0f, 0.0f));

	if (Input::IsKeyPressed(SDL_SCANCODE_UP))
		SetRotation(GetRotation() - glm::vec3(0.5f, 0.0f, 0.0f));
	if (Input::IsKeyPressed(SDL_SCANCODE_DOWN))
		SetRotation(GetRotation() + glm::vec3(0.5f, 0.0f, 0.0f));
	if (Input::IsKeyPressed(SDL_SCANCODE_LEFT))
		SetRotation(GetRotation() - glm::vec3(0.0f, 0.5f, 0.0f));
	if (Input::IsKeyPressed(SDL_SCANCODE_RIGHT))
		SetRotation(GetRotation() + glm::vec3(0.0f, 0.5f, 0.0f));
}
