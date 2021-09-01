
#pragma once

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include "State.h"

class Game
{
	static Game* instance;

public:

	// Constructor.
	Game(std::string tittle, int width, int height);
	~Game();

	void Init();
	void Run();

	SDL_Renderer* GetRenderer() { return renderer; }
	State& GetState() { return *state; }

public:
	static Game* GetInstance();

private:

	/* Renderer */
	std::string gameTitle;
	int height;
	int width;

	SDL_Window* window;
	SDL_Renderer* renderer;
	State* state;
};

inline
Game* Game::GetInstance()
{
	return instance;
}

#define APPLICATION Game::GetInstance()
