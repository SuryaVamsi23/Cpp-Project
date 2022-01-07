#include "ExitButton.hpp"
ExitButton::ExitButton(string s) : Component(s)
{
    exit_button = new Button(720, 5, 60, 60, "exit.png");
    mouse = new Mouse;
    isClicked = false;
}
void ExitButton::handleEvents()
{
    if (isActiveComponent)
    {
        if (exit_button->isclicked(mouse))
        {
            isClicked = true;
        }
    }
}
void ExitButton::update(vector<Component *> &Components, bool *isRunning)
{
    if (isClicked == true)
    {
        int i;
        for (i = 0; i < Components.size(); i++)
        {
            Components[i]->setInactive();
        }
        isClicked = false;
        *isRunning = false;
    }
}
bool ExitButton::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        exit_button->place_button(renderer);
    }
    return (true);
}