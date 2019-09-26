// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <iostream>

#include "../CortabloEngine.h"
#include "../sys/Window.h"
#include "../renderer/Shader.h"
#include "../renderer/Renderer.h"
#include "../renderer/RenderCommand.h"
#include "../renderer/camera/PerspectiveCamera.h"
#include "../utils/Map.h"

class ModelViewer
{
private:
	Window* m_Window;

	Shader* m_MainShader, * m_CubeMapShader;

	Renderer* m_ModelRenderer;

	Map* m_Map;

	PerspectiveCamera* m_Camera;

	RenderCommand* m_RenderCommand;
public:
	ModelViewer();
	~ModelViewer();

	void Update();
};
