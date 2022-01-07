#include "Game_Background.hpp"
#include "ComponentManager.hpp"
Game_Background::Game_Background(string s) : Component(s)
{
    surface = IMG_Load("room.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void Game_Background::handleEvents()
{
}
void Game_Background::update(vector<Component *> &Components, bool *isRunning)
{
}
bool Game_Background::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        SDL_RenderCopy(renderer, texture, NULL, NULL);
    }

    return (true);
}