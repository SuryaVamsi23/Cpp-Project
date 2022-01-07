#include "Dustbin2.hpp"
#include "ComponentManager.hpp"
Dustbin2::Dustbin2(string s) : Component(s)
{
    r = new SDL_Rect();
    surface = IMG_Load("dustbin.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void Dustbin2::handleEvents()
{
}
void Dustbin2::update(vector<Component *> &Components, bool *isRunning)
{
}
bool Dustbin2::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        r->x = 425;
        r->y = 250;
        r->w = 150;
        r->h = 100;
        SDL_RenderCopy(renderer, texture, NULL, r);
    }
    return (true);
}