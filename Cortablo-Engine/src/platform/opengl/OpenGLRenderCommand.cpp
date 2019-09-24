// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLRenderCommand.h"

OpenGLRenderCommand::OpenGLRenderCommand()
{
	// OpenGL: Depth-Test
	glEnable(GL_DEPTH_TEST);

	// OpenGL: Blending
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);

	// OpenGL: Face-Culling
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
	glEnable(GL_CULL_FACE);
}

OpenGLRenderCommand::~OpenGLRenderCommand()
{

}

void OpenGLRenderCommand::SetClearColor(const glm::vec4& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}

void OpenGLRenderCommand::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLRenderCommand::SetRenderMode(unsigned int mode)
{
	glPolygonMode(GL_FRONT_AND_BACK, mode);
}
