// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <glm/glm.hpp>

#include "Texture.h"
#include "ObjModel.h"

class GameObject
{
private:
	glm::vec3 m_Position, m_Rotation, m_Scale;
	Texture* m_Texture;
	ObjModel* m_ObjModel;
public:
	GameObject(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale, Texture* texture, ObjModel* objModel);
	~GameObject();

	const glm::vec3& GetPosition();
	const glm::vec3& GetRotation();
	const glm::vec3& GetScale();

	ObjModel* GetModel();

	Texture* GetTexture();

	virtual void Update();
};