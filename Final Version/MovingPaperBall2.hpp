#pragma once

#include "Utilities.hpp"
#include "Component.hpp"
#include "Winner.hpp"
#include "ExitButton.hpp"
#include "Dustbin.hpp"
#include "Game_Background.hpp"
#include "StationaryPaperBall.hpp"
class PowerBar;
class ComponentManager;
class MovingPaperBall2 : public Component
{
public:
    MovingPaperBall2(string s, int v, int a);
    void handleEvents();
    void update(vector<Component *> &Components, bool *isRunning);
    bool render(SDL_Renderer *renderer, vector<Component *> &Components);
private:
    SDL_Rect *r;
    Uint32 startTime;
    int count = 1;
    int velocity;
    int angle;
    bool win;
    bool entryflag;
};