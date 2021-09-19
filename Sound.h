#pragma once

#include <string>
#include <SDL_mixer.h>
#include "Component.h"

class Sound 
	: public Component
{
public:
	Sound(GameObject& associated);
	Sound(GameObject& associated, std::string file);
	~Sound();

public:
	void Open(std::string file);
	void Play(int times = 1);
	void Stop();

public:
	void Update(float dt) override {};
	void Render() override {};

public:
	bool IsOpen() { return chunk != nullptr; }
	bool Is(std::string type) override { return type.compare("Sound") == 0; }

private:
	Mix_Chunk* chunk;
	int channel;
};

