#pragma once
#include "Utilities.hpp"
#include "Component.hpp"
#include "Button.hpp"
#include "Mouse.hpp"
#include "Dustbin.hpp"
#include "MovingPaperBall.hpp"
class ComponentManager;
class AngleBar : public Component
{
public:
    AngleBar(string s, int v);
    void animateAngleBar();
    void handleEvents();
    void update(vector<Component *> &Components, bool *isRunning);
    bool render(SDL_Renderer *renderer, vector<Component *> &Components);
private:
    SDL_Rect *r;
    SDL_Rect rects[10];
    Uint32 startTime;
    Uint32 endTime;
    Button *AngleBarButton;
    Mouse *mouse;
    bool isClicked;
    int count;
    int bar_render_ticks;
    int velocity;
    int angle;
    int angle_max;
};