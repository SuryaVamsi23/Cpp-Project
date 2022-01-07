#include "Dustbin.hpp"
#include "ComponentManager.hpp"
Dustbin::Dustbin(string s) : Component(s)
{
    r = new SDL_Rect();
    surface = IMG_Load("dustbin.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void Dustbin::handleEvents()
{
}
void Dustbin::update(vector<Component *> &Components, bool *isRunning)
{
}
bool Dustbin::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        r->x = 600;
        r->y = 320;
        r->w = 150;
        r->h = 100;
        SDL_RenderCopy(renderer, texture, NULL, r);
    }
    return (true);
}