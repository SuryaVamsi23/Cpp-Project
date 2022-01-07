#pragma once
#include "Utilities.hpp"
#include "Component.hpp"
#include "Button.hpp"
class ExitButton : public Component
{
public:
    ExitButton(string s);
    void handleEvents();
    void update(vector<Component *> &Components, bool *isRunning);
    bool render(SDL_Renderer *renderer, vector<Component *> &Components);
private:
    Button *exit_button;
    Mouse *mouse;
    bool isClicked;
};