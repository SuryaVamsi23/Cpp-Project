#include "ComponentManager.hpp"
#include "startButton.hpp"
#include "ExitButton.hpp"
#include "MainBackground.hpp"

int* ComponentManager::t = (int *)malloc(sizeof(int) * 2);
SDL_Window* ComponentManager::main_window = SDL_CreateWindow("Paper Toss", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 480, 0);
SDL_Renderer* ComponentManager::renderer = SDL_CreateRenderer(main_window, -1, 0);
void ComponentManager::init()
{
    SDL_RenderClear(renderer);
}
void ComponentManager::begin_game()
{
    init();
    vector<Component *> Components;
    Component *m = new MainBackground("Main background");
    Component *s = new startButton("Start Button");
    Component *e = new ExitButton("Exit button");
    m->setActive();
    s->setActive();
    e->setActive();
    Components.push_back(m);
    Components.push_back(s);
    Components.push_back(e);
    bool isRunning = true;
    Mouse *mouse = new Mouse();
    const int FPS = 60;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;
    bool temp = true;

    while (isRunning)
    {
        SDL_PumpEvents();
        frameStart = SDL_GetTicks();

        SDL_RenderClear(renderer);
        int i;
        for (i = 0; i < Components.size(); i++)
        {
            temp = true;
            if(Components[i]->isActiveComponent)
                Components[i]->handleEvents();
            if(Components[i]->isActiveComponent)
                Components[i]->update(Components, &isRunning);
            if(Components[i]->isActiveComponent)
                temp = Components[i]->render(renderer, Components);
        }
        SDL_RenderPresent(renderer);
        frameTime = SDL_GetTicks() - frameStart;
        if (frameTime < frameDelay)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}