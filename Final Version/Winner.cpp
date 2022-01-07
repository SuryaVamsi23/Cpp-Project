#include "Winner.hpp"
#include "ComponentManager.hpp"
Winner::Winner(string s) : Component(s)
{
    surface = IMG_Load("Winner.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void Winner::handleEvents()
{
}
void Winner::update(vector<Component *> &Components, bool *isRunning)
{
}
bool Winner::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        SDL_RenderCopy(renderer, texture, NULL, NULL);
    }

    return (true);
}