// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <glm/glm.hpp>

#include "../CortabloEngine.h"

class Shader
{
public:
	static Shader* Init(const std::string& vertexFilePath, const std::string& fragmentFilePath);
	virtual ~Shader() = default;

	virtual void Bind() = 0;
	virtual void Unbind() = 0;

	virtual int GetUniformLocation(const char* name) = 0;
	virtual void SetUniform1i(const std::string& location, int value) = 0;
	virtual void SetUniform1iv(const std::string& location, int count, int* value) = 0;
	virtual void SetUniform1f(const std::string& location, float value) = 0;
	virtual void SetUniform1fv(const std::string& location, int count, float* value) = 0;
	virtual void SetUniform2f(const std::string& location, const glm::vec2& value) = 0;
	virtual void SetUniform3f(const std::string& location, const glm::vec3& value) = 0;
	virtual void SetUniform4f(const std::string& location, const glm::vec4& value) = 0;
	virtual void SetUniformMatrix4fv(const std::string& location, const glm::mat4& value) = 0;
};