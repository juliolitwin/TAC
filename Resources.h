#pragma once

#include <string>
#include <unordered_map>
#include <SDL.h>
#include <SDL_mixer.h>

class Resources
{
    static Resources* instance;

public:
    static Resources* GetInstance();

public:
    Resources();

public:
    SDL_Texture* GetImage(std::string file);
    void ClearImages();

    Mix_Music* GetMusic(std::string file);
    void ClearMusics();

    Mix_Chunk* GetSound(std::string file);
    void ClearSounds();

private:
    std::unordered_map<std::string, SDL_Texture*> imageTable;
    std::unordered_map<std::string, Mix_Music*> musicTable;
    std::unordered_map<std::string, Mix_Chunk*> soundTable;
};

inline
Resources* Resources::GetInstance()
{
    if (instance == NULL)
        instance = new Resources();

    return instance;
}

#define RESOURCES Resources::GetInstance()