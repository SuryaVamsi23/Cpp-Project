#pragma once
using namespace std;
#include "Utilities.hpp"
#include "Component.hpp"
#include "Dustbin.hpp"
#include "Game_Background.hpp"
#include "StationaryPaperBall.hpp"
#include "ExitButton.hpp"
#include "Table.hpp"
#include "Dustbin2.hpp"
#include "Level2.hpp"
class PowerBar;
class PowerBar2;
class ComponentManager;
class MovingPaperBall : public Component
{
public:
    MovingPaperBall(string s, int v, int a);
    void handleEvents();
    void update(vector<Component *> &Components, bool *isRunning);
    bool render(SDL_Renderer *renderer, vector<Component *> &Components);
private:
    SDL_Rect *r;
    Uint32 startTime;
    int count = 1;
    bool entryflag;
    int angle;
    int velocity;
};