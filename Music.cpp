#include "Music.h"

Music::Music(GameObject& associated)
	:Component(associated)
{
	music = nullptr;
}

Music::Music(GameObject& associated, std::string file)
	: Component(associated)
{
	music = nullptr;
	Open(file);
}

Music::~Music()
{
	if(music != nullptr)
		Mix_FreeMusic(music);
}

void Music::Play(int times)
{
	if (music != nullptr)
	{
		Mix_PlayMusic(music, times);
	}
}

void Music::Stop(int msToStop)
{
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file)
{
	music = Mix_LoadMUS(file.c_str());
	if (music == nullptr)
	{
		printf(SDL_GetError());
		return;
	}

	Play();
}
