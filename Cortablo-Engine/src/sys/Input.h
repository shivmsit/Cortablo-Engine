// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include <SDL2//SDL.h>
#include <glm//glm.hpp>

class Input
{
public:
	static bool m_KeyboardKeys[1024];
	static bool m_MouseButtons[32];
	static SDL_Window* m_Window;

	static void OnKeyDown(SDL_Scancode scancode);
	static void OnKeyUp(SDL_Scancode scancode);
	static void OnMouseButtonDown(uint8_t button);
	static void OnMouseButtonUp(uint8_t button);

	static bool IsKeyPressed(SDL_Scancode scancode);
	static bool IsMouseButtonPressed(uint8_t button);

	static void GetMousePosition(int& x, int& y);
	static void SetMousePosition(int x, int y);
	static void SetMousePosition(const glm::vec2& position);

	static void ShowCursor(bool show);
	static void GrabCursor(bool grab);
};