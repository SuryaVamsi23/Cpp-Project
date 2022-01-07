#pragma once
#include "Utilities.hpp"
#include "Mouse.hpp"
class ComponentManager;
class Button
{
public:
    Button(int x, int y, int h, int w, string s);
    void place_button(SDL_Renderer *renderer);
    bool cursor_on_button(Mouse *m);
    bool isclicked(Mouse *m);
    int get_x_coordinate();
    int get_y_coordinate();
    string get_contents();
private:
    SDL_Surface *s;
    SDL_Texture *t;
    SDL_Rect *r;
    int x_cordinate;
    int y_cordinate;
    int width;
    int height;
    string content;
};