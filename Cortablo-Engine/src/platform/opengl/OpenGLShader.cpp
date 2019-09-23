// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLShader.h"

OpenGLShader::OpenGLShader(const std::string& vertexFilePath, const std::string& fragmentFilePath)
{
	GLuint shaderProgram = glCreateProgram();

	/* ============= */
	/* Vertex-Shader */
	/* ============= */

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

	std::optional<std::string> vertexShaderSource = FileSystem::ReadFile(vertexFilePath);
	if (vertexShaderSource.has_value())
	{
		printf("[OpenGL] Vertex source loaded!\n");

		const char* vertexShaderSrc = vertexShaderSource.value().c_str();

		glShaderSource(vertexShader, 1, &vertexShaderSrc, NULL);
		glCompileShader(vertexShader);

		GLint result;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(vertexShader, length, &length, &error[0]);
			printf("[OpenGL] Error: Vertex source could not be compiled!\n");
			printf("[OpenGL] %s\n", &error[0]);
			glDeleteShader(vertexShader);
		}
		else
		{
			printf("[OpenGL] Vertex source compiled!\n");
		}
	}
	else
	{
		printf("[OpenGL] Error: Vertex source could not be loaded!\n");
	}

	/* =============== */
	/* Fragment-Shader */
	/* =============== */

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

	std::optional<std::string> fragmentShaderSource = FileSystem::ReadFile(fragmentFilePath);
	if (fragmentShaderSource.has_value())
	{
		printf("[OpenGL] Fragment source loaded!\n");

		const char* fragmentShaderSrc = fragmentShaderSource.value().c_str();

		glShaderSource(fragmentShader, 1, &fragmentShaderSrc, NULL);
		glCompileShader(fragmentShader);

		GLint result;
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE)
		{
			GLint length;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &length);
			std::vector<char> error(length);
			glGetShaderInfoLog(fragmentShader, length, &length, &error[0]);
			printf("[OpenGL] Error: Fragment source could not be compiled!\n");
			printf("[OpenGL] %s\n", &error[0]);
			glDeleteShader(fragmentShader);
		}
		else
		{
			printf("[OpenGL] Fragment source compiled!\n");
		}
	}
	else
	{
		printf("[OpenGL] Error: Fragment source could not be loaded!\n");
	}

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);
	glValidateProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	m_ShaderID = shaderProgram;
}

OpenGLShader::~OpenGLShader()
{
	Unbind();
	glDeleteProgram(m_ShaderID);
}

void OpenGLShader::Bind()
{
	glUseProgram(m_ShaderID);
}
void OpenGLShader::Unbind()
{
	glUseProgram(NULL);
}

int OpenGLShader::GetUniformLocation(const char* name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
		return m_UniformLocationCache[name];

	GLuint uniformLocation = glGetUniformLocation(m_ShaderID, name);

	if (uniformLocation == -1)
		printf("[OpenGL] Warning: The uniform location '%s' does not exist!\n", name);
	else
		m_UniformLocationCache[name] = uniformLocation;

	return uniformLocation;
}

void OpenGLShader::SetUniform1i(const std::string& location, int value)
{
	glUniform1i(GetUniformLocation(location.c_str()), value);
}

void OpenGLShader::SetUniform1iv(const std::string& location, int count, int* value)
{
	glUniform1iv(GetUniformLocation(location.c_str()), count, value);
}

void OpenGLShader::SetUniform1f(const std::string& location, float value)
{
	glUniform1f(GetUniformLocation(location.c_str()), value);
}

void OpenGLShader::SetUniform1fv(const std::string& location, int count, float* value)
{
	glUniform1fv(GetUniformLocation(location.c_str()), count, value);
}

void OpenGLShader::SetUniform2f(const std::string& location, const glm::vec2& value)
{
	glUniform2f(GetUniformLocation(location.c_str()), value.x, value.y);
}

void OpenGLShader::SetUniform3f(const std::string& location, const glm::vec3& value)
{
	glUniform3f(GetUniformLocation(location.c_str()), value.x, value.y, value.z);
}
void OpenGLShader::SetUniform4f(const std::string& location, const glm::vec4& value)
{
	glUniform4f(GetUniformLocation(location.c_str()), value.x, value.y, value.z, value.w);
}

void OpenGLShader::SetUniformMatrix4fv(const std::string& location, const glm::mat4& value)
{
	glUniformMatrix4fv(GetUniformLocation(location.c_str()), 1, false, &value[0][0]);
}
