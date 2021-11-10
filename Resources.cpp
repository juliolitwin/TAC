#include "Resources.h"
#include "Game.h"
#include <assert.h>

Resources* Resources::instance = 0;

Resources::Resources()
{
    assert(instance == 0 && "bad singleton");
    instance = this;
}

SDL_Texture* Resources::GetImage(std::string file)
{
    auto it = imageTable.find(file.c_str());
    if (it != imageTable.end())
        return it->second;

    SDL_Texture* texture = IMG_LoadTexture(APPLICATION->GetRenderer(), file.c_str());
    imageTable[file.c_str()] = texture;

    return texture;
}

void Resources::ClearImages()
{
    for (auto it = imageTable.begin(); it != imageTable.end(); it++)
    {
        if (it->second != nullptr)
            SDL_DestroyTexture(it->second);
    }

    imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file)
{
    auto it = musicTable.find(file.c_str());

    if (it != musicTable.end())
        return it->second;

    Mix_Music* music = Mix_LoadMUS(file.c_str());
    musicTable[file.c_str()] = music;

    return music;
}

void Resources::ClearMusics()
{
    for (auto it = musicTable.begin(); it != musicTable.end(); it++)
    {
        if (it->second != nullptr)
            Mix_FreeMusic(it->second);
    }

    musicTable.clear();
}

Mix_Chunk* Resources::GetSound(std::string file)
{
    auto it = soundTable.find(file.c_str());

    if (it != soundTable.end())
        return it->second;

    Mix_Chunk* sound = Mix_LoadWAV(file.c_str());
    soundTable[file.c_str()] = sound;

    return sound;
}

void Resources::ClearSounds()
{
    for (auto it = soundTable.begin(); it != soundTable.end(); it++)
    {
        if (it->second != nullptr)
            Mix_FreeChunk(it->second);
    }

    soundTable.clear();
}