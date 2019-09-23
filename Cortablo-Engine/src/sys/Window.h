// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../CortabloEngine.h"

class Window
{
public:
	static Window* Init(const std::string& title, int width, int height);
	virtual ~Window() = default;

	virtual void Update() = 0;
	virtual void Shutdown() = 0;

	virtual void SetSize(int width, int height) = 0;
	virtual void SetTitle(const std::string& title) = 0;
	virtual void SetIcon(const std::string& filePath) = 0;
};