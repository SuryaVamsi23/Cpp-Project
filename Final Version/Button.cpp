#include "Button.hpp"
#include "ComponentManager.hpp"
Button::Button(int x, int y, int h, int w, string strg)
{
    r = new SDL_Rect();
    x_cordinate = x;
    y_cordinate = y;
    width = w;
    height = h;
    content = strg;

    char ch  = strg.front();
    if(ch == 'e' || ch == 'E')
    {
        s = IMG_Load("exit.png");
        t = SDL_CreateTextureFromSurface(ComponentManager::renderer, s);
        SDL_FreeSurface(s);
    }
    else
    {
        s = IMG_Load("start.png");
        t = SDL_CreateTextureFromSurface(ComponentManager::renderer, s);
        SDL_FreeSurface(s);
    }
}

void Button::place_button(SDL_Renderer *renderer)
{
    r->x = this->x_cordinate;
    r->y = this->y_cordinate;
    r->h = this->height;
    r->w = this->width;
    SDL_RenderCopy(renderer, t, NULL, r);
}

bool Button::cursor_on_button(Mouse *m)
{
    int mouse_x = m->get_mouse_x();
    int mouse_y = m->get_mouse_y();

    if ((mouse_x > this->x_cordinate) && (mouse_x < this->x_cordinate + this->width))
    {
        if ((mouse_y > this->y_cordinate) && (mouse_y < this->y_cordinate + this->height))
        {
            return true;
        }

        return false;
    }
    return false;
}

bool Button::isclicked(Mouse *m)
{
    if (this->cursor_on_button(m) && m->isclicked())
    {
        return true;
    }

    return false;
}

int Button::get_x_coordinate()
{
    return (x_cordinate);
}

int Button::get_y_coordinate()
{
    return (y_cordinate);
}

string Button::get_contents()
{
    return (content);
}