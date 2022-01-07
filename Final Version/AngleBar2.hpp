#pragma once
#include "Utilities.hpp"
#include "Component.hpp"
#include "Button.hpp"
#include "Dustbin2.hpp"
#include "MovingPaperBall2.hpp"
class ComponentManager;
class AngleBar2 : public Component
{
public:
    AngleBar2(string s, int v);
    void animate();
    void handleEvents();
    void update(vector<Component *> &Components, bool *isRunning);
    bool render(SDL_Renderer *renderer, vector<Component *> &Components);
private:
    SDL_Rect *r;
    SDL_Rect rects[10];
    Uint32 startTime;
    Uint32 endTime;
    Button *AngleBarButton;
    int count;
    Mouse *mouse;
    bool isClicked;
    int velocity;
    int angle;
    int bar_render_ticks;
};