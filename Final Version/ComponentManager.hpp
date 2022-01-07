#pragma once
#include "Utilities.hpp"
#include "Component.hpp"
#include "Mouse.hpp"
class MainBackground;
class ExitButton;
class StartButton;
class ComponentManager
{
public:
    static SDL_Renderer *renderer;
    static SDL_Window *main_window;
    static int* t;
    void init();
    void begin_game();
    int* get_t()
    {
        return t;
    }
    static void set_t(int subscript, int val)
    {
        t[subscript] = val;
    }
};

