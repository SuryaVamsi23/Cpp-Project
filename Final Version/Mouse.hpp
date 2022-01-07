#pragma once
#include "Utilities.hpp"
class Mouse
{
public:
    int get_mouse_x();
    int get_mouse_y();
    bool isclicked();
private:
    int x_coordinate;
    int y_coordinate;
};