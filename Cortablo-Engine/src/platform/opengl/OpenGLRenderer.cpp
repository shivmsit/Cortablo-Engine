// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLRenderer.h"

OpenGLRenderer::OpenGLRenderer(Shader* shader) : m_Shader(shader)
{
	Clear();

	m_VAO = VertexArray::Init();
}

OpenGLRenderer::~OpenGLRenderer()
{
	Clear();

	m_VBO->Unbind();
	m_VAO->Unbind();

	delete m_VBO;
	delete m_VAO;
}

void OpenGLRenderer::Add(GameObject* gameObject)
{
	m_RendererQueue.push_back(gameObject);
}

void OpenGLRenderer::Add(const std::vector<GameObject*>& gameObjects)
{
	m_RendererQueue.insert(m_RendererQueue.end(), gameObjects.begin(), gameObjects.end());
}

void OpenGLRenderer::Render()
{
	if (!m_RendererQueue.empty())
	{
		for (unsigned int i = 0; i < m_RendererQueue.size(); i++)
		{
			m_Shader->Bind();
			m_VAO->Bind();
			m_RendererQueue[i]->GetTexture()->Bind();

			m_VBO = VertexBuffer::Init(m_RendererQueue[i]->GetModel()->GetVertices().size() * sizeof(glm::vec3), &m_RendererQueue[i]->GetModel()->GetVertices().front());
			m_VBO->AddSubData(m_RendererQueue[i]->GetModel()->GetVertices().size() * sizeof(glm::vec3), m_RendererQueue[i]->GetModel()->GetUVs().size() * sizeof(glm::vec2), &m_RendererQueue[i]->GetModel()->GetUVs().front());
			m_VBO->AddSubData(sizeof(glm::vec3) + sizeof(glm::vec2), m_RendererQueue[i]->GetModel()->GetNormals().size() * sizeof(glm::vec3), &m_RendererQueue[i]->GetModel()->GetNormals().front());

//		glBufferSubData(GL_ARRAY_BUFFER, m_RendererQueue[i]->GetModel()->GetVertices().size() * sizeof(glm::vec3), m_RendererQueue[i]->GetModel()->GetUVs().size() * sizeof(glm::vec2), &m_RendererQueue[i]->GetModel()->GetUVs().front());
//			glBufferSubData(GL_ARRAY_BUFFER, sizeof(glm::vec3) + sizeof(glm::vec2), m_RendererQueue[i]->GetModel()->GetNormals().size() * sizeof(glm::vec3), &m_RendererQueue[i]->GetModel()->GetNormals().front());


			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (const void*)0);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (const void*)0);
			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (const void*)0);

			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			glEnableVertexAttribArray(2);

			m_IBO = IndexBuffer::Init(&m_RendererQueue[i]->GetModel()->GetVertexIndices().front(), m_RendererQueue[i]->GetModel()->GetVertexIndices().size() * sizeof(unsigned int));

			m_Shader->SetUniformMatrix4fv("modelMatrix",
				glm::translate(glm::mat4(1.0f), m_RendererQueue[i]->GetPosition()) *
				glm::rotate(m_ModelMatrix, glm::radians(m_RendererQueue[i]->GetRotation().x), glm::vec3(0.0f, 1.0f, 0.0f)) *
				glm::rotate(m_ModelMatrix, glm::radians(m_RendererQueue[i]->GetRotation().y), glm::vec3(1.0f, 0.0f, 0.0f)) *
				glm::scale(m_ModelMatrix, m_RendererQueue[i]->GetScale())
			);
			m_ModelMatrix = glm::mat4(1.0f);

			glDrawElements(GL_TRIANGLES, m_RendererQueue[i]->GetModel()->GetVertexIndices().size(), GL_UNSIGNED_INT, NULL);

			glDisableVertexAttribArray(0);
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(2);

			m_IBO->Unbind();
			m_VBO->Unbind();
			m_VAO->Unbind();
		}
	}
}
void OpenGLRenderer::RenderString(const std::string& text, const glm::vec3& position, const Font& font, const glm::vec4& color)
{

	if (FT_Init_FreeType(&m_FreeTypeLibrary))
	{
		printf("[Font] Error: FreeType2 could not be initialized!\n");
		__debugbreak();
	}
	else
	{
		printf("[Font] FreeType2 initialized!\n");
	}

	if (FT_New_Face(m_FreeTypeLibrary, font.GetFilePath().c_str(), 0, &m_FreeTypeFace))
	{
		printf("[Font] Error: FreeType2-Face could not be created!\n");
		__debugbreak();
	}
	else
	{
		printf("[Font] FreeType2-Face created!\n");
	}

	FT_Set_Pixel_Sizes(m_FreeTypeFace, 0, font.GetSize());

	for (unsigned int i = 0; i < text.length(); i++)
	{
		if (FT_Load_Char(m_FreeTypeFace, text[i], FT_LOAD_RENDER))
		{
			printf("[Font] Error: Glyph could not be loaded!\n");
			__debugbreak();
		}
		//m_RendererQueue.push_back(new Plane(glm::vec3(position.x+i, position.y, position.z), glm::vec3(0.0f), glm::vec3(1.0f), new Texture(GL_LINEAR, m_FreeTypeFace->glyph->bitmap.width, m_FreeTypeFace->glyph->bitmap.rows, m_FreeTypeFace->glyph->bitmap.buffer)));
	}

	FT_Done_Face(m_FreeTypeFace);
	FT_Done_FreeType(m_FreeTypeLibrary);
	printf("[Font] FreeType2 terminated!\n");
}

void OpenGLRenderer::Update()
{

}

void OpenGLRenderer::Clear()
{
	m_RendererQueue.clear();
}
