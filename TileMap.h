#pragma once

#include <vector>
#include <string>

#include "GameObject.h"
#include "Component.h"
#include "TileSet.h"

class TileMap
	: public Component
{
public:
    TileMap(GameObject& associated, std::string file, TileSet* tileSet);

public:
    void Load(std::string file);

    void Render() override;
    void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
    void Update(float dt) override {};

public:
    void SetTileSet(TileSet* tileSet) { this->tileSet = tileSet; }

    int& At(int x, int y, int z) { return tileMatrix[x + y * mapWidth + z * mapWidth * mapHeight]; }

    int GetWidth() { return mapWidth; }
    int GetHeight() { return mapHeight; }
    int GetDepth() { return mapDepth; }

public:
	bool Is(std::string type) override { return type.compare("TileMap") == 0; }

private:
    std::vector<int> tileMatrix;
    TileSet* tileSet;
    
    int mapWidth;
    int mapHeight;
    int mapDepth;
};

