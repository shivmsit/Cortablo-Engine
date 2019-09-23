// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Input.h"

	bool Input::m_KeyboardKeys[1024], Input::m_MouseButtons[32];
	SDL_Window* Input::m_Window;

	void Input::OnKeyDown(SDL_Scancode scancode)
	{
		m_KeyboardKeys[scancode] = true;
	}

	void Input::OnKeyUp(SDL_Scancode scancode)
	{
		m_KeyboardKeys[scancode] = false;
	}

	void Input::OnMouseButtonDown(uint8_t button)
	{
		m_MouseButtons[button] = true;
	}

	void Input::OnMouseButtonUp(uint8_t button)
	{
		m_MouseButtons[button] = false;
	}

	bool Input::IsKeyPressed(SDL_Scancode scancode)
	{
		return m_KeyboardKeys[scancode];
	}

	bool Input::IsMouseButtonPressed(uint8_t button)
	{
		return m_MouseButtons[button];
	}

	void Input::GetMousePosition(int& x, int& y)
	{
		SDL_GetMouseState(&x, &y);
	}

	void Input::SetMousePosition(int x, int y)
	{
		SDL_WarpMouseInWindow(m_Window, x, y);
	}

	void Input::SetMousePosition(const glm::vec2& position)
	{
		SDL_WarpMouseInWindow(m_Window, position.x, position.y);
	}

	void Input::ShowCursor(bool show)
	{
		SDL_ShowCursor(show == true ? 1 : 0);
	}

	void Input::GrabCursor(bool grab)
	{
		SDL_CaptureMouse(grab == true ? SDL_TRUE : SDL_FALSE);
	}