#include "StationaryPaperBall.hpp"
#include "ComponentManager.hpp"
StationaryPaperBall::StationaryPaperBall(string s) : Component(s)
{
    r = new SDL_Rect();
    r->x = 0;
    r->y = 370;
    r->w = 50;
    r->h = 50;

    surface = IMG_Load("paper.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void StationaryPaperBall::handleEvents()
{
}
void StationaryPaperBall::update(vector<Component *> &Components, bool *isRunning)
{
}
bool StationaryPaperBall::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        SDL_RenderCopy(renderer, texture, NULL, r);
    }
    return (true);
}