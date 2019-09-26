// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include <iostream>

#include "CortabloEngine.h"
#include "template/Template.h"
#include "utils/Timer.h"
#include "modelviewer/ModelViewer.h"

int main(int argc, char* argv[])
{
	Timer* timer = new Timer();

	for (int i = 1; i < argc - 1; i++)
	{
		if (argv[i][0] != '-') i++;
		CortabloEngine::LaunchParameters::Set(argv[i], argv[i + 1]);
	}

	CortabloEngine::EngineParameters::Set("engineName", "Cortablo-Engine");
	CortabloEngine::EngineParameters::Set("engineVersion", "alpha 0.1");

	printf("[Engine] %s (Version: %s)\n", CortabloEngine::EngineParameters::Get<const char*>("engineName"), CortabloEngine::EngineParameters::Get<const char*>("engineVersion"));

#if 0
	Template* game = new Template();

	game->Update();

	delete game;
#else
	ModelViewer* game = new ModelViewer();

	game->Update();

	delete game;
#endif

	printf("[Engine] Engine terminated!\n");

	printf("[Engine] Runtime: %fs\n", timer->GetElapsedSeconds());
	delete timer;

	return 0;
}
