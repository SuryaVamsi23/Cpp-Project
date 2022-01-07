#include "MainBackground.hpp"
#include "ComponentManager.hpp"
MainBackground::MainBackground(string s) : Component(s)
{
    surface = IMG_Load("main.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void MainBackground::handleEvents()
{
}
void MainBackground::update(vector<Component *> &Components, bool *isRunning)
{
}
bool MainBackground::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        SDL_RenderCopy(renderer, texture, NULL, NULL);
    }

    return (true);
}