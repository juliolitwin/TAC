#pragma once

#include <string>
#include <SDL.h>

class Sprite
{
public:
	Sprite();
	Sprite(std::string file);

	~Sprite();

public:
	void Open(std::string file);
	void SetClip(int x, int y, int w, int h);
	void Render(int x, int y);

public:
	int GetWidth() { return width; }
	int GetHeight() { return height; }
	bool IsOpen() { return ((texture != nullptr) ? true : false); }

private:
	SDL_Texture* texture;

	int width;
	int height;
	SDL_Rect clipRect;
};

