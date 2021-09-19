#include "Game.h"
#include "time.h"
#include <assert.h>

Game* Game::instance = 0;

Game::Game(std::string title, int w, int h)
{
	assert(instance == 0 && "bad singleton");
	instance = this;

	gameTitle = title;
	width = w;
	height = h;

	Init();
}

Game::~Game()
{
	delete state;

	IMG_Quit();

	Mix_CloseAudio();
	Mix_Quit();

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}

void Game::Init()
{
	// Init SDL.
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) < 0)
	{
		printf(SDL_GetError());
		return;
	}

	// Image init.
	if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) < 0)
	{
		printf(SDL_GetError());
		return;
	}

	int flags = MIX_INIT_OGG | MIX_INIT_MOD;
	if ((Mix_Init(flags) & flags) != flags)
	{
		printf(SDL_GetError());
		return;
	}

	//Initialize SDL2_mixer
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) < 0)
	{
		printf(SDL_GetError());
		return;
	}

	// Create the Window.
	window = SDL_CreateWindow(gameTitle.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WindowFlags::SDL_WINDOW_ALLOW_HIGHDPI);
	if (window == NULL)
	{
		printf(SDL_GetError());
		return;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		printf(SDL_GetError());
		return;
	}

	state = new State();
}

void Game::Run()
{
	while (state->QuitRequested() == false)
	{
		state->Update(0.0f);
		state->Render();

		SDL_Delay(33);
	}
}
