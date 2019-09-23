// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "GameObject.h"

GameObject::GameObject(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& scale, Texture* texture, ObjModel* objModel) : m_Position(position), m_Rotation(rotation), m_Scale(scale), m_Texture(texture), m_ObjModel(objModel)
{

}

GameObject::~GameObject()
{

}

void GameObject::Update()
{

}

const glm::vec3& GameObject::GetPosition()
{
	return m_Position;
}

const glm::vec3& GameObject::GetRotation()
{
	return m_Rotation;
}

const glm::vec3& GameObject::GetScale()
{
	return m_Scale;
}

Texture* GameObject::GetTexture()
{
	return m_Texture;
}

ObjModel* GameObject::GetModel()
{
	return m_ObjModel;
}
