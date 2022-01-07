#pragma once
#include "Utilities.hpp"
#include "Component.hpp"
#include "Button.hpp"
#include "Mouse.hpp"
#include "Game_Background.hpp"
#include "Dustbin.hpp"
#include "ExitButton.hpp"
#include "StationaryPaperBall.hpp"
class PowerBar;
class ComponentManager;
class startButton : public Component
{
public:
    startButton(string s);
    void handleEvents();
    void update(vector<Component *> &Components, bool *isRunning);
    bool render(SDL_Renderer *renderer, vector<Component *> &Components);
private:
    Button *start_button;
    Mouse *mouse;
    bool isClicked;
};