#pragma once
#include "Utilities.hpp"
#include "Component.hpp"
class ComponentManager;
class StationaryPaperBall : public Component
{
public:
    StationaryPaperBall(string s);
    void handleEvents();
    void update(vector<Component *> &Components, bool *isRunning);
    bool render(SDL_Renderer *renderer, vector<Component *> &Components);
private:
    SDL_Rect *r;
};