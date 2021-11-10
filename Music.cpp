#include "Music.h"
#include "Resources.h"

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
#if false
	if(music != nullptr)
		Mix_FreeMusic(music);
#endif
}

void Music::Play(int times)
{
	if (music != nullptr)
		Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop)
{
	Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file)
{
	music = RESOURCES->GetMusic(file);
	if (music == nullptr)
	{
		printf(SDL_GetError());
		return;
	}

	Play();
}
