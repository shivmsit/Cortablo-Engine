// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include <iostream>

#include "CortabloEngine.h"
#include "template/Template.h"

#define USE_TEMPLATE 1

int main(int argc, char* argv[])
{
	for (int i = 1; i < argc - 1; i++)
	{
		if (argv[i][0] != '-') i++;
		CortabloEngine::LaunchParameters::Set(argv[i], argv[i + 1]);
	}

	CortabloEngine::EngineParameters::Set("engineName", "Cortablo-Engine");
	CortabloEngine::EngineParameters::Set("engineVersion", "alpha 0.1");

	printf("[Engine] %s (Version: %s)\n", CortabloEngine::EngineParameters::Get<const char*>("engineName"), CortabloEngine::EngineParameters::Get<const char*>("engineVersion"));
	   	  
#ifdef USE_TEMPLATE
	Template* game = new Template();
	game->Update();
	delete game;
#endif

	printf("[Engine] Engine terminated!\n");

	return 0;
}
