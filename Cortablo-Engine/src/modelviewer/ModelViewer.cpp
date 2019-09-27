// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "ModelViewer.h"

ModelViewer::ModelViewer()
{
	CortabloEngine::GameParameters::Set("gameName", (std::string)"Cortablo-Engine: Model-Viewer");
	CortabloEngine::GameParameters::Set("gameVersion", (std::string)"alpha 0.1");

	printf("[Game] %s (Version: %s\n", CortabloEngine::GameParameters::Get<std::string>("gameName").c_str(), CortabloEngine::GameParameters::Get<std::string>("gameVersion").c_str());

	m_Window = Window::Init(CortabloEngine::GameParameters::Get<std::string>("gameName"), 1920, 1080);

	m_MainShader = Shader::Init("src/template/shaders/main.vert", "src/template/shaders/main.frag");
	m_CubeMapShader = Shader::Init("src/template/shaders/cubeMap.vert", "src/template/shaders/cubeMap.frag");
	m_MainShader->Bind();

	m_ModelRenderer = Renderer::Init(m_MainShader);

	m_Map = new Map("src/modelviewer/maps/modelMap.json");
	m_ModelRenderer->Add(m_Map->GetGameObjects());

	m_Camera = new PerspectiveCamera(45.0f, 16.0f / 9.0f, glm::vec3(0.0f, 0.0f, -100.0f), glm::vec3(0.0f));
	m_Camera->SetMove(false);
	m_Camera->SetLook(false);
	m_MainShader->SetUniformMatrix4fv("projectionMatrix", m_Camera->GetProjectionMatrix());

	m_RenderCommand = RenderCommand::Init();
	m_RenderCommand->SetClearColor(glm::vec4(0.0f, 0.0f, 0.4f, 0.0f));	
}

ModelViewer::~ModelViewer()
{
	delete m_RenderCommand;
	delete m_Camera;
	delete m_Map;
	delete m_ModelRenderer;
	delete m_MainShader;
	delete m_CubeMapShader;
	delete m_Window;
	printf("[Game] Game terminated!\n");
}

void ModelViewer::Update()
{
	while (CortabloEngine::EngineParameters::Get<bool>("engineRunning"))
	{
		m_RenderCommand->Clear();

		m_Camera->SetRotation(glm::vec3(m_Camera->GetRotation().x, m_Camera->GetRotation().y + 1.0f, m_Camera->GetRotation().z));

		m_ModelRenderer->Render();
		m_ModelRenderer->Update();

		m_Camera->Update();
		m_MainShader->SetUniformMatrix4fv("viewMatrix", m_Camera->GetViewMatrix());

		m_Window->Update();
	}
}