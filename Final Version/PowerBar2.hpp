#pragma once
#include "Utilities.hpp"
#include "Component.hpp"
#include "Button.hpp"
#include "AngleBar2.hpp"
class ComponentManager;
class PowerBar2 : public Component
{
public:
    PowerBar2(string s);
    void animatePowerButton();
    void handleEvents();
    void update(vector<Component *> &Components, bool *isRunning);
    bool render(SDL_Renderer *renderer, vector<Component *> &Components);
private:
    SDL_Rect *r;
    Uint32 startTime;
    Uint32 endTime;
    Button *PowerBarButton;
    Mouse *mouse;
    SDL_Rect rects[10];
    bool isClicked;
    int AnimationTime = 10;
    int count = 0;
    int max_velocity;
    int bar_render_ticks;
    int velocity;
};