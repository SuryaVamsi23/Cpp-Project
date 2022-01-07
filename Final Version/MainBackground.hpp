#pragma once
#include "Utilities.hpp"
#include "Component.hpp"
class ComponentManager;
class MainBackground : public Component
{
public:
    MainBackground(string s);
    void handleEvents();
    void update(vector<Component *> &Components, bool *isRunning);
    bool render(SDL_Renderer *renderer, vector<Component *> &Components);
};