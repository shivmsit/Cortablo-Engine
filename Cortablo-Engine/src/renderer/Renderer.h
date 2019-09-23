// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../CortabloEngine.h"

#include <vector>
#include "GameObject.h"
#include "Font.h"
#include "Shader.h"

class Renderer
{
private:
public:
	static Renderer* Init(Shader* shader);
	virtual ~Renderer() = default;

	virtual void Add(GameObject* gameObject) = 0;
	virtual void Add(const std::vector<GameObject*>& gameObjects) = 0;

	virtual void Render() = 0;
	virtual void RenderString(const std::string& text, const glm::vec3& position, const Font& font, const glm::vec4& color) = 0;
	virtual void Update() = 0;
	virtual void Clear() = 0;
};
