#include "Level2.hpp"
#include "ComponentManager.hpp"
Level2::Level2(string s) : Component(s)
{
    surface = IMG_Load("room.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void Level2::handleEvents()
{
}
void Level2::update(vector<Component *> &Components, bool *isRunning)
{
}
bool Level2::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        SDL_RenderCopy(renderer, texture, NULL, NULL);
    }
    return (true);
}