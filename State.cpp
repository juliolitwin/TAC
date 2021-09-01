#include "State.h"

State::State()
{
	quitRequested = false;

	LoadAssets();
}

State::~State()
{
	if (sprite != nullptr)
		delete sprite;

	if (music != nullptr)
		delete music;
}

void State::LoadAssets()
{
	sprite = new Sprite(".\\data\\img\\ocean.jpg");
	music = new Music(".\\data\\audio\\stageState.ogg");
}

void State::Update(float dt)
{
	if (SDL_QuitRequested()) 
	{
		quitRequested = true;
	}
}

void State::Render()
{
	sprite->Render(0, 0);
}
