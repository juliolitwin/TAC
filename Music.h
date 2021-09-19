#pragma once

#include <string>
#include <SDL_mixer.h>
#include "Component.h"

class Music
	: public Component
{
public:
	Music(GameObject& associated);
	Music(GameObject& associated, std::string file);
	~Music();

public:
	void Play(int times = -1);
	void Stop(int msToStop = 1500);
	void Open(std::string file);

public:
	void Update(float dt) override {};
	void Render() override {};
	
public:
	bool IsOpen() { return (music != nullptr) ? true : false; }

public:
	bool Is(std::string type) override { return type.compare("Music") == 0; }

private:
	Mix_Music* music;
};

