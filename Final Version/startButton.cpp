#include "startButton.hpp"
#include "PowerBar.hpp"
#include "ComponentManager.hpp"
startButton::startButton(string s) : Component(s)
{
    start_button = new Button(25, 240, 50, 100, "start.png");
    mouse = new Mouse;
    isClicked = false;
}
void startButton::handleEvents()
{
    if (isActiveComponent)
    {
        if (start_button->isclicked(mouse))
        {
            isClicked = true;
        }
    }
}
void startButton::update(vector<Component *> &Components, bool *isRunning)
{
    if (isClicked == true)
    {
        int i;
        for (i = 0; i < Components.size(); i++)
        {
            Components[i]->setInactive();
        }
        Component *g = new Game_Background("Game Background");
        Component *d = new Dustbin("Dust bin");
        Component *p = new StationaryPaperBall("Stationary paper");
        Component *pb = new PowerBar("Power bar");
        ComponentManager::t[0] = SDL_GetTicks();
        Component *e = new ExitButton("Exit button");
        g->setActive();
        d->setActive();
        p->setActive();
        pb->setActive();
        e->setActive();
        Components.push_back(g);
        Components.push_back(d);
        Components.push_back(p);
        Components.push_back(pb);
        Components.push_back(e);
        isClicked = false;
    }
}
bool startButton::render(SDL_Renderer *renderer, vector<Component *> &Components)
{
    if (isActiveComponent)
    {
        start_button->place_button(renderer);
    }
    return (true);
}