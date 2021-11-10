#include <iostream>
#include "TileSet.h"

TileSet::TileSet(GameObject& associated, int tileWidth, int tileHeight, std::string file)
    : tileSet(associated, file)
{
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;

    if (!tileSet.IsOpen())
    {
        printf("Unable to load the tileset.");

        columns = 0;
        rows = 0;
        
        return;
    }

    columns = tileSet.GetWidth() / tileWidth;
    rows = tileSet.GetHeight() / tileHeight;
}

void TileSet::RenderTile(unsigned index, int x, int y)
{
    auto id = (unsigned)rows * columns - 1;
    if (index < id)
    {
        tileSet.SetClip(
            (index % columns) * tileWidth, 
            (index / columns) * tileHeight, 
            tileWidth, tileHeight);

        tileSet.Render(x, y);
    }
}
