#pragma once

#include "Utilities.hpp"
class Component
{
public:
    bool isActiveComponent;
    SDL_Surface *surface;
    SDL_Texture *texture;
    string type;
    Component(string s);
    void setActive();
    void setInactive();
    string get_type();
    virtual void handleEvents() = 0;
    virtual void update(vector<Component *> &Components, bool *isRunning) = 0;
    virtual bool render(SDL_Renderer *renderer, vector<Component *> &Components) = 0;
};