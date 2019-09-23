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
			m_RendererQueue[i]->GetTexture()->Bind();

			m_VAO->Bind();

			if (!m_RendererQueue[i]->GetModel()->GetVertices().empty())
			{
				m_VBO = VertexBuffer::Init(&m_RendererQueue[i]->GetModel()->GetVertices().front(), (unsigned int)m_RendererQueue[i]->GetModel()->GetVertices().size() * sizeof(float));
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (const void*)0);
			}

			if (!m_RendererQueue[i]->GetModel()->GetUVs().empty())
			{
				m_TexCoord = VertexBuffer::Init(&m_RendererQueue[i]->GetModel()->GetUVs().front(), (unsigned int)m_RendererQueue[i]->GetModel()->GetUVs().size() * sizeof(float));
				glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, (const void*)0);
			}

			if (!m_RendererQueue[i]->GetModel()->GetNormals().empty())
			{
				m_Normal = VertexBuffer::Init(&m_RendererQueue[i]->GetModel()->GetNormals().front(), (unsigned int)m_RendererQueue[i]->GetModel()->GetNormals().size() * sizeof(float));
				glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (const void*)0);
			}

			glEnableVertexAttribArray(0);
			if (!m_RendererQueue[i]->GetModel()->GetUVs().empty())
				glEnableVertexAttribArray(1);
			if (!m_RendererQueue[i]->GetModel()->GetNormals().empty())
				glEnableVertexAttribArray(2);

#if 1
			m_IBO = IndexBuffer::Init(&m_RendererQueue[i]->GetModel()->GetFaces().front(), (unsigned int)m_RendererQueue[i]->GetModel()->GetFaces().size() * sizeof(unsigned int));
#endif

			m_ModelMatrix = glm::translate(glm::mat4(1.0f), m_RendererQueue[i]->GetPosition());
			m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_RendererQueue[i]->GetRotation().x), glm::vec3(0.0f, 1.0f, 0.0f));
			m_ModelMatrix = glm::rotate(m_ModelMatrix, glm::radians(m_RendererQueue[i]->GetRotation().y), glm::vec3(1.0f, 0.0f, 0.0f));
			m_ModelMatrix = glm::scale(m_ModelMatrix, m_RendererQueue[i]->GetScale());
			m_Shader->SetUniformMatrix4fv("modelMatrix", m_ModelMatrix);

#if 1
			glDrawElements(GL_TRIANGLES, (unsigned int)m_RendererQueue[i]->GetModel()->GetFaces().size(), GL_UNSIGNED_INT, NULL);
#else
			glDrawArrays(GL_TRIANGLES, 0, (unsigned int)m_RendererQueue[i]->GetModel()->GetVertices().size());
#endif

			glDisableVertexAttribArray(0);
			if (!m_RendererQueue[i]->GetModel()->GetUVs().empty())
				glDisableVertexAttribArray(1);
			if (!m_RendererQueue[i]->GetModel()->GetNormals().empty())
				glDisableVertexAttribArray(2);

#if 1
			m_IBO->Unbind();
#endif
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
		return;
	}
	else
	{
		printf("[Font] FreeType2 initialized!\n");
	}

	if (FT_New_Face(m_FreeTypeLibrary, font.GetFilePath().c_str(), 0, &m_FreeTypeFace))
	{
		printf("[Font] Error: FreeType2-Face could not be created!\n");
		return;
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
			return;
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
