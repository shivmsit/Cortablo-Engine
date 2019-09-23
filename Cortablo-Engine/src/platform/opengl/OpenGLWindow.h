// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <SDL2/SDL.h>
#include "../../renderer/Context.h"
#include "../../renderer/Texture.h"
#include "../../sys/Input.h"
#include "../../sys/Window.h"

class OpenGLWindow : public Window
{
private:
	SDL_Window* m_SDLWindow;
	Context* m_Context;
public:
	OpenGLWindow(const std::string& title, int width, int height);
	~OpenGLWindow();

	void Update() override;
	void Shutdown() override;

	void SetSize(int width, int height) override;
	void SetTitle(const std::string& title) override;
	void SetIcon(const std::string& filePath) override;
};