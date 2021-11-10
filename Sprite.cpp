#include "Sprite.h"
#include "Game.h"
#include "Resources.h"

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
#if false
	if (texture != nullptr)
		SDL_DestroyTexture(texture);
#endif
}

void Sprite::Open(std::string file)
{
	texture = RESOURCES->GetImage(file);
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
	Render(associated.box.x, associated.box.y);
}

void Sprite::Render(int x, int y)
{
	SDL_Rect dst;

	dst.x = x;
	dst.y = y;
	dst.w = clipRect.w;
	dst.h = clipRect.h;

	if (SDL_RenderCopy(APPLICATION->GetRenderer(), texture, &clipRect, &dst) != 0)
	{
		printf(SDL_GetError());
		return;
	}

#if false
	SDL_RenderPresent(APPLICATION->GetRenderer());
#endif
}