#include "Template.h"

Template::Template()
{
	CortabloEngine::GameParameters::Set("gameName", (std::string)"Cortablo-Engine: Template");
	CortabloEngine::GameParameters::Set("gameVersion", (std::string)"alpha 0.1");

	printf("[Game] %s (Version: %s)\n", CortabloEngine::GameParameters::Get<std::string>("gameName").c_str(), CortabloEngine::GameParameters::Get <std::string>("gameVersion").c_str());

	m_Window = Window::Init(CortabloEngine::GameParameters::Get<std::string>("gameName"), 1920, 1080);

	m_MainShader = Shader::Init("src/template/shaders/mainVertex.glsl", "src/template/shaders/mainFragment.glsl");
	m_MainShader->Bind();

	m_WorldRenderer = Renderer::Init(m_MainShader);

	m_Map = new Map("src/template/maps/template.json");
	m_WorldRenderer->Add(m_Map->GetGameObjects());

	m_Camera = new PerspectiveCamera(45.0f, 16.0f / 9.0f, glm::vec3(0.0f), glm::vec3(0.0f));
	m_MainShader->SetUniformMatrix4fv("projectionMatrix", m_Camera->GetProjectionMatrix());

	m_RenderCommand = RenderCommand::Init();
	m_RenderCommand->SetClearColor(glm::vec4(0.4f, 0.4f, 0.7f, 1.0f));
}

Template::~Template()
{
	delete m_RenderCommand;
	delete m_Camera;
	delete m_Map;
	delete m_WorldRenderer;
	delete m_MainShader;
	delete m_Window;
	printf("[Game] Game terminated!\n");
}

void Template::Update()
{
	while (CortabloEngine::EngineParameters::Get<bool>("engineRunning"))
	{
		m_RenderCommand->Clear();

		m_WorldRenderer->Render();
		m_WorldRenderer->Update();

		m_Camera->Update();
		m_MainShader->SetUniformMatrix4fv("viewMatrix", m_Camera->GetViewMatrix());

		m_Window->Update();
	}
}
