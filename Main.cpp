#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;
class Window
{

public:
    Window(string s)
    {
        SDL_Window *main_window = SDL_CreateWindow("Paper Toss", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 480, 0);
        renderer = SDL_CreateRenderer(main_window, -1, 0);
        SDL_Texture *texture = IMG_LoadTexture(renderer, s.c_str());
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
        //cout<<renderer<<endl;
    }

    SDL_Renderer *get_renderer()
    {
        return (renderer);
    }

    void update(string s)
    {

        SDL_Texture *texture = IMG_LoadTexture(renderer, s.c_str());
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

private:
    SDL_Window *main_window;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
};

class Mouse
{

public:
    int get_mouse_x()
    {
        SDL_GetMouseState(&x_coordinate, &y_coordinate);
        return (x_coordinate);
    }

    int get_mouse_y()
    {
        SDL_GetMouseState(&x_coordinate, &y_coordinate);
        return (y_coordinate);
    }

    bool isclicked()
    {
        Uint32 cursors = SDL_GetMouseState(&x_coordinate, &y_coordinate);

        if ((cursors & SDL_BUTTON_LMASK) != 0)
        {
            return true;
        }

        return false;
    }

private:
    int x_coordinate;
    int y_coordinate;
};
class Button
{
public:
    Button(int x, int y, int h, int w, string s)
    {

        x_cordinate = x;
        y_cordinate = y;
        width = w;
        height = h;
        content = s;
    }

    void place_button(Window *m)
    {
        SDL_Texture *t = IMG_LoadTexture(m->get_renderer(), content.c_str());
        SDL_Rect *r = new SDL_Rect();
        r->x = this->x_cordinate;
        r->y = this->y_cordinate;
        r->h = this->height;
        r->w = this->width;
        SDL_RenderCopy(m->get_renderer(), t, NULL, r);
        SDL_RenderPresent(m->get_renderer());
    }

    bool cursor_on_button(Mouse *m)
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

    bool isclicked(Mouse *m)
    {

        if (this->cursor_on_button(m) && m->isclicked())
        {
            return true;
        }

        return false;
    }

    int get_x_coordinate()
    {
        return (x_cordinate);
    }

    int get_y_coordinate()
    {
        return (y_cordinate);
    }

private:
    int x_cordinate;
    int y_cordinate;
    int width;
    int height;
    string content;
};

int main()
{
    bool m_screen = true;
    bool i_screen = false;
    bool g_screen = false; 
    Window *main_screen = new Window("main.png");
    Button *start_button;
    start_button = new Button(25, 240, 50, 100, "start.png");
    start_button->place_button(main_screen);
    Button *exit_button = new Button(720, 5, 60, 60, "exit.png");
    exit_button->place_button(main_screen);
    Mouse *m = new Mouse();
    bool f = false;
    while (1)
    {
        SDL_PumpEvents();
        if (exit_button->isclicked(m))
        {
            break;
        }
        if (m_screen)
        {

            if (start_button->isclicked(m))
            {
                cout << "It is working" << endl;
                m_screen = false;
                g_screen = true;
            }
        }

        if (g_screen)
        {
            SDL_RenderClear(main_screen->get_renderer());
            if (f == false)
            {
                Button *dustbin = new Button(600,320,100,150,"dustbin.png");
                main_screen->update("room.png");
                exit_button->place_button(main_screen);
                dustbin->place_button(main_screen);
                f = true;
            }
        }
    }

    return 0;
}
