// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <glm/ext.hpp>

#include "../../renderer/Renderer.h"
#include "../../renderer/buffer/VertexBuffer.h"
#include "../../renderer/buffer/IndexBuffer.h"
#include "../../renderer/buffer/VertexArray.h"

#include <ft2build.h>
#include FT_FREETYPE_H


class OpenGLRenderer : public Renderer
{
private:
	Shader* m_Shader;

	VertexArray* m_VAO;
	VertexBuffer* m_VBO, * m_TexCoord, * m_Normal;
	IndexBuffer* m_IBO;

	glm::mat4 m_ModelMatrix;

	std::vector<GameObject*> m_RendererQueue;

	FT_Library m_FreeTypeLibrary;
	FT_Face m_FreeTypeFace;

public:
	OpenGLRenderer(Shader* shader);
	~OpenGLRenderer();

	void Add(GameObject* gameObject) override;
	void Add(const std::vector<GameObject*>& gameObjects) override;

	void Render() override;
	void RenderString(const std::string& text, const glm::vec3& position, const Font& font, const glm::vec4& color) override;
	void Update() override;
	void Clear() override;
};