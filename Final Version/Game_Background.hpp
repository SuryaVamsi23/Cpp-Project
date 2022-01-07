#pragma once
#include "Utilities.hpp"
#include "Component.hpp"
class ComponentManager;
class Game_Background : public Component
{
public:
    Game_Background(string s);
    void handleEvents();
    void update(vector<Component *> &Components, bool *isRunning);
    bool render(SDL_Renderer *renderer, vector<Component *> &Components);
};