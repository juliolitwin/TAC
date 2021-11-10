#pragma once

#include <string>
#include "Sprite.h"

class TileSet
{
public:
	TileSet(GameObject& associated, int tileWidth, int tileHeight, std::string file);

public:
	void RenderTile(unsigned index, int x, int y);

	int GetTileWidth() { return tileWidth; }
	int GetTileHeight() { return tileHeight; }

private:
	Sprite tileSet;

	int rows;
	int columns;
	
	int tileWidth;
	int tileHeight;
};

