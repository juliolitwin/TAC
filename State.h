#pragma once

#include <memory>
#include <vector>
#include "GameObject.h"

class State
{
public:
	State();
	~State();

public:
	bool QuitRequested() { return quitRequested; }
	void LoadAssets();

public:
	void Update(float dt);
	void Render();

private:
	void Input();
	void AddObject(int mouseX, int mouseY);

private:
	bool quitRequested;

	std::vector<std::unique_ptr<GameObject>> objectArray;
};

