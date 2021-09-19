#include "Sound.h"

Sound::Sound(GameObject& associated)
	: Component(associated)
	, chunk(nullptr)
	, channel(0)
{
}

Sound::Sound(GameObject& associated, std::string file)
	: Component(associated)
{
	Open(file);
}

Sound::~Sound()
{
	if (chunk == nullptr)
		return;

	Mix_HaltChannel(channel);
	Mix_FreeChunk(chunk);
}

void Sound::Play(int times)
{
	if (chunk == nullptr)
		return;

	channel = Mix_PlayChannel(1, chunk, times);
	if (channel == -1)
	{
		printf(SDL_GetError());
	}
}

void Sound::Stop()
{
	if (chunk == nullptr)
		return;

	Mix_HaltChannel(channel);
}

void Sound::Open(std::string file)
{
	chunk = Mix_LoadWAV(file.c_str());
	if (chunk != nullptr)
	{
		printf(SDL_GetError());
	}
}
