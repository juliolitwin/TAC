#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(GameObject& associated)
	: Component(associated)
	, texture(nullptr)
{
}

Sprite::Sprite(GameObject& associated, std::string file)
	: Component(associated)
	, texture(nullptr)
{
	Open(file);
}

Sprite::~Sprite()
{
	if (texture != nullptr)
		SDL_DestroyTexture(texture);
}

void Sprite::Open(std::string file)
{
	texture = IMG_LoadTexture(APPLICATION->GetRenderer(), file.c_str());
	if (texture == nullptr)
	{
		printf(SDL_GetError());
		return;
	}

	SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
	SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h)
{
	clipRect.x = x;
	clipRect.y = y;
	clipRect.w = w;
	clipRect.h = h;
}

void Sprite::Render()
{
	SDL_Rect dst;
	
	dst.x = (int)associated.box.x;
	dst.y = (int)associated.box.y;
	dst.w = clipRect.w;
	dst.h = clipRect.h;

	if (SDL_RenderCopy(APPLICATION->GetRenderer(), texture, &clipRect, &dst) != 0)
	{
		printf(SDL_GetError());
		return;
	}

	SDL_RenderPresent(APPLICATION->GetRenderer());
}
