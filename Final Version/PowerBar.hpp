#pragma once

#include "Utilities.hpp"
#include "Component.hpp"
#include "Button.hpp"
#include "Mouse.hpp"
#include "AngleBar.hpp"
class ComponentManager;
class PowerBar : public Component
{
public:
    PowerBar(string s, int x=150, int y=390);
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
    int AnimationTime;
    int count;
    int max_velocity;
    int velocity;
    int bar_render_ticks;
};