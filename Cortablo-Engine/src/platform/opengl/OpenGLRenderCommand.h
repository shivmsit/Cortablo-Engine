// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../../renderer/RenderCommand.h"

#include <GL/glew.h>

class OpenGLRenderCommand : public RenderCommand
{
private:

public:
	OpenGLRenderCommand();
	~OpenGLRenderCommand();

	void SetClearColor(const glm::vec4& color) override;
	void Clear() override;
	void SetRenderMode(unsigned int mode) override;
};