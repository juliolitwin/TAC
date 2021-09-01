#pragma once

#include "Sprite.h"
#include "Music.h"

class State
{
public:
	State();
	~State();

public:
	bool QuitRequested() { return quitRequested; }

	void LoadAssets();
	void Update(float dt);
	void Render();

private:
	Music* music;
	Sprite* sprite;
	bool quitRequested;
};

