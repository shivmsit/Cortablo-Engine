// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#pragma once

#include "../CortabloEngine.h"

#include <iostream>

#include <SDL2/SDL_mixer.h>

class Music
{
private:
	Mix_Music* m_MixMusic;
public:
	Music(const std::string& filePath);
	~Music();

	void Play();
	void Stop();
	void Pause();
	void SetVolume(int volume);
};

class Sound
{
private:
	Mix_Chunk* m_MixChunk;
public:
	Sound(const std::string& filePath);
	~Sound();

	void Play();
	void Stop();
	void Pause();
	void SetVolume(int volume);
};