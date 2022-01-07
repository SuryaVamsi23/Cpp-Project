#include "Table.hpp"
#include "ComponentManager.hpp"
Table::Table(string s) : Component(s)
{
    r = new SDL_Rect();

    surface = IMG_Load("table.png");
    texture = SDL_CreateTextureFromSurface(ComponentManager::renderer, surface);
    SDL_FreeSurface(surface);
}
void Table::handleEvents()
{
}
void Table::update(vector<Component *> &Components, bool *isRunning)
{
}
bool Table::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        r->x = 400;
        r->y = 275;
        r->w = 200;
        r->h = 250;
        SDL_RenderCopy(renderer, texture, NULL, r);
    }
    return (true);
}