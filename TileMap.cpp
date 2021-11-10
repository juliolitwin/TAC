#include <string.h>
#include <iostream>
#include <fstream>

#include "TileMap.h"

TileMap::TileMap(GameObject& associated, std::string file, TileSet* tileSet) 
	: Component(associated)
{
	this->tileSet = tileSet;
	Load(file);
}

void TileMap::Load(std::string file)
{
	FILE* mapFile;
	auto err = fopen_s(&mapFile, file.c_str(), "r");
	if (err != 0 || mapFile == NULL)
	{
		printf("Unable to load the tilemap.");
		return;
	}

	fscanf_s(mapFile, "%d,%d,%d,", &mapWidth, &mapHeight, &mapDepth);
	int buffer;

	for (int d = 0; d < mapDepth; d++)
	{
		for (int h = 0; h < mapHeight; h++)
		{
			for (int w = 0; w < mapWidth; w++)
			{
				fscanf_s(mapFile, "%d,", &buffer);
				tileMatrix.push_back(buffer - 1);
			}
		}
	}

	fclose(mapFile);
}

void TileMap::Render()
{
	for (int i = 0; i < mapDepth; i++)
		RenderLayer(i, associated.box.x, associated.box.y);
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY)
{
	for (int h = 0; h < mapHeight; h++)
	{
		for (int w = 0; w < mapWidth; w++)
		{
			tileSet->RenderTile(
				tileMatrix[
					w + h * mapWidth + layer * mapWidth * mapHeight],
				w * tileSet->GetTileWidth() + cameraX,
						h * tileSet->GetTileHeight() + cameraY);
		}
	}
}