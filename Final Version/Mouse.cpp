#include "Mouse.hpp"
int Mouse::get_mouse_x()
{
    SDL_GetMouseState(&x_coordinate, &y_coordinate);
    return (x_coordinate);
}
int Mouse::get_mouse_y()
{
    SDL_GetMouseState(&x_coordinate, &y_coordinate);
    return (y_coordinate);
}
bool Mouse::isclicked()
{
    Uint32 cursors = SDL_GetMouseState(&x_coordinate, &y_coordinate);

    if ((cursors & SDL_BUTTON_LMASK) != 0)
    {
        return true;
    }

    return false;
}