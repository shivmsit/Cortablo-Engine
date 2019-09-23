// *****************| Cortablo-Engine |*****************
// * Copyright (c) 2019 Cortablo. All rights reserved. *
// *****************************************************

#include "Audio.h"

#define MIX_EVERYTHING MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID | MIX_INIT_OPUS

#define FREQUENCY 22050

Music::Music(const std::string & filePath)
{
	if (Mix_Init(MIX_EVERYTHING) == 0)
	{
		printf("[Engine] Error: SDL2_Mixer could not be initialized!\n");
		return;
	}
	else
		printf("[Engine] SDL2_Mixer initialized!\n");

	if (Mix_OpenAudio(FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
	{
		printf("[Audio] Error: Mix_OpenAudio failed!\n");
		return;
	}
	else
		printf("[Audio] Mix_OpenAudio successfully completed!\n");

	m_MixMusic = Mix_LoadMUS(filePath.c_str());
	if (!m_MixMusic)
	{
		printf("[Audio] Error: Mix_LoadMUS failed!\n");
		printf("[Audio] -> File: %s\n", filePath.c_str());
		return;
	}
	else
		printf("[Audio] Mix_LoadMus successfully completed!\n");
}

Music::~Music()
{
	Mix_FreeMusic(m_MixMusic);
	Mix_CloseAudio();
	Mix_Quit();
	printf("[Engine] SDL2_Mixer terminated!\n");
}

void Music::Play()
{
	if (Mix_PausedMusic())
		Mix_ResumeMusic();
	else
		Mix_PlayMusic(m_MixMusic, -1);
}

void Music::Stop()
{
	Mix_HaltMusic();
}

void Music::Pause()
{
	Mix_PauseMusic();
}

void Music::SetVolume(int volume)
{
	Mix_VolumeMusic(volume);
}

Sound::Sound(const std::string& filePath)
{
	if (Mix_Init(MIX_EVERYTHING) == 0)
	{
		printf("[Engine] Error: SDL2_Mixer could not be initialized!\n");
		return;
	}
	else
		printf("[Engine] SDL2_Mixer initialized!\n");

	if (Mix_OpenAudio(FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096) != 0)
	{
		printf("[Audio] Error: Mix_OpenAudio failed!\n");
		return;
	}
	else
		printf("[Audio] Mix_OpenAudio successfully completed!\n");

	m_MixChunk = Mix_LoadWAV(filePath.c_str());
	if (!m_MixChunk)
	{
		printf("[Audio] Mix_LoadWAV failed!\n");
		printf("[Audio] -> File: %s\n", filePath.c_str());
		return;
	}
	else
		printf("[Audio] Mix_LoadWAV successfully completed!\n");
}

Sound::~Sound()
{
	Mix_FreeChunk(m_MixChunk);
	Mix_CloseAudio();
	Mix_Quit();
	printf("[Engine] SDL2_Mixer terminated!\n");
}

void Sound::Play()
{
	if (Mix_Paused(-1))
		Mix_Resume(-1);
	else
		Mix_PlayChannel(-1, m_MixChunk, 0);
}

void Sound::Stop()
{
	Mix_HaltChannel(-1);
}

void Sound::Pause()
{
	Mix_Pause(-1);
}

void Sound::SetVolume(int volume)
{
	Mix_Volume(-1, volume);
}
