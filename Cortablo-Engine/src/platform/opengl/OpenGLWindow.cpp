// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "OpenGLWindow.h"

OpenGLWindow::OpenGLWindow(const std::string& title, int width, int height)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("[Engine] SDL2 could not be initialized!\n");
		printf("[Engine] -> Error: %s\n", SDL_GetError());
		__debugbreak();
	}
	else
		printf("[Engine] (%s) SDL2 initialized!\n", __FUNCTION__);

#ifdef __APPLE__
	// Für NVIDIA GeForce 9600M GT unter macOS Mojave
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
#endif

	m_SDLWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	if (!m_SDLWindow)
	{
		printf("[Window] (%s) Error: Window could not be created!\n", __FUNCTION__);
		printf("[Window] (%s) -> Error: %s\n", __FUNCTION__, SDL_GetError());
		__debugbreak();
	}
	else
	{
		printf("[Window] (%s) Window created!\n", __FUNCTION__);
		printf("[Window] (%s) -> Width: %i\n", __FUNCTION__, CortabloEngine::EngineParameters::Get<int>("windowWidth"));
		printf("[Window] (%s) -> Height: %i\n", __FUNCTION__, CortabloEngine::EngineParameters::Get<int>("windowHeight"));
		printf("[Window] (%s) -> Title: %s\n", __FUNCTION__, CortabloEngine::EngineParameters::Get<std::string>("windowTitle").c_str());
	}

	if (CortabloEngine::LaunchParameters::Check("-fullscreen"))
		SDL_SetWindowFullscreen(m_SDLWindow, 1);

	m_Context = Context::Init(m_SDLWindow);

	if (glewInit() != GLEW_OK)
	{
		printf("[OpenGL] (%s) Error: GLEW could not be initialized!\n", __FUNCTION__);
		__debugbreak();
	}
	else
		printf("[OpenGL] (%s) GLEW initialized!\n", __FUNCTION__);

	Input::m_Window = m_SDLWindow;
	CortabloEngine::EngineParameters::Set("engineRunning", true);
}

OpenGLWindow::~OpenGLWindow()
{
	Shutdown();
	delete m_Context;
}

void OpenGLWindow::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			Shutdown();
			break;
		case SDL_KEYDOWN:
			Input::OnKeyDown(event.key.keysym.scancode);
			break;
		case SDL_KEYUP:
			Input::OnKeyUp(event.key.keysym.scancode);
			break;
		case SDL_MOUSEBUTTONDOWN:
			Input::OnMouseButtonDown(event.button.button);
			break;
		case SDL_MOUSEBUTTONUP:
			Input::OnMouseButtonUp(event.button.button);
			break;
		}
	}
	m_Context->SwapBuffers();
}

void OpenGLWindow::Shutdown()
{
	m_Context->Shutdown();
	SDL_DestroyWindow(m_SDLWindow);
	printf("[Engine] (%s) Window terminated!\n", __FUNCTION__);
	SDL_Quit();
	printf("[Engine] (%s) SDL2 terminated!\n", __FUNCTION__);
	CortabloEngine::EngineParameters::Set("engineRunning", false);
}

void OpenGLWindow::SetSize(int width, int height)
{
	CortabloEngine::EngineParameters::Set("windowWidth", width);
	CortabloEngine::EngineParameters::Set("windowHeight", height);
	SDL_SetWindowSize(m_SDLWindow, width, height);
}

void OpenGLWindow::SetTitle(const std::string& title)
{
	CortabloEngine::EngineParameters::Set("windowTitle", title);
	SDL_SetWindowTitle(m_SDLWindow, title.c_str());
}

void OpenGLWindow::SetIcon(const std::string& filePath)
{
	Texture* texture = Texture::Init(filePath);

#if SDL_BYTEORDER == SDL_BIG_ENDIAN // Big Endian
	int shift = (texture->GetBPP() == 3 ? 8 : 0);
	SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(texture->GetPixels(), texture->GetWidth(), texture->GetHeight(), texture->GetBPP() == 3 ? 24 : 32, texture->GetBPP() == 3 ? 3 * texture->GetWidth() : 4 * texture->GetWidth(), 0xff000000 >> shift, 0x00ff0000 >> shift, 0x0000ff00 >> shift, 0x000000ff >> shift);
#else // Little Endian
	SDL_Surface* surface = SDL_CreateRGBSurfaceFrom(texture->GetPixels(), texture->GetWidth(), texture->GetHeight(), texture->GetBPP() == 3 ? 24 : 32, texture->GetBPP() == 3 ? 3 * texture->GetWidth() : 4 * texture->GetWidth(), 0x000000ff, 0x0000ff00, 0x00ff0000, texture->GetBPP() == 3 ? 0 : 0xff000000);
#endif

	if (!surface)
	{
		printf("[Window] (%s) Error: Surface could not be created!\n", __FUNCTION__);
		return;
	}
	else
		printf("[Window] (%s) Surface created!\n", __FUNCTION__);

	SDL_SetWindowIcon(m_SDLWindow, surface);
	SDL_FreeSurface(surface);
}

