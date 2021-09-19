#pragma once

#include <string>
#include <SDL.h>
#include "Component.h"

class GameObject;

class Sprite 
	: public Component
{
public:
	Sprite(GameObject& associated);
	Sprite(GameObject& associated, std::string file);

	~Sprite();

public:
	void Open(std::string file);
	void SetClip(int x, int y, int w, int h);

	void Update(float dt) override {}
	void Render() override;

public:
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	bool IsOpen() { return ((texture != nullptr) ? true : false); }

public:
	bool Is(std::string type) override { return type.compare("Sprite") == 0; }

private:
	SDL_Texture* texture;

	int width;
	int height;
	SDL_Rect clipRect;
};

