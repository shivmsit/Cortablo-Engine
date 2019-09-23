// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../../renderer/Shader.h"
#include "../../sys/FileSystem.h"

#include <iostream>
#include <GL/glew.h>
#include <unordered_map>
#include <glm/glm.hpp>

class OpenGLShader : public Shader
{
private:
	uint32_t m_ShaderID;
	std::unordered_map<std::string, GLint> m_UniformLocationCache;

public:
	OpenGLShader(const std::string& vertexFilePath, const std::string& fragmentFilePath);
	~OpenGLShader();

	void Bind() override;
	void Unbind() override;

	int GetUniformLocation(const char* name) override;
	void SetUniform1i(const std::string& location, int value) override;
	void SetUniform1iv(const std::string& location, int count, int* value) override;
	void SetUniform1f(const std::string& location, float value) override;
	void SetUniform1fv(const std::string& location, int count, float* value) override;
	void SetUniform2f(const std::string& location, const glm::vec2& value) override;
	void SetUniform3f(const std::string& location, const glm::vec3& value) override;
	void SetUniform4f(const std::string& location, const glm::vec4& value) override;
	void SetUniformMatrix4fv(const std::string& location, const glm::mat4& value) override;
};
