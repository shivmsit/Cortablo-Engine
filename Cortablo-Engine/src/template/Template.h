#pragma once

#include "../CortabloEngine.h"
#include "../sys/Window.h"
#include "../renderer/Shader.h"
#include "../renderer/Renderer.h"
#include "../renderer/RenderCommand.h"
#include "../renderer/camera/PerspectiveCamera.h"
#include "../utils/Map.h"

class Template
{
private:
	Window* m_Window;
	Shader* m_MainShader;
	Renderer* m_WorldRenderer;
	Map* m_Map;
	PerspectiveCamera* m_Camera;
	RenderCommand* m_RenderCommand;
public:
	Template();
	~Template();

	void Update();
};