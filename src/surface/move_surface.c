#include "visual.h"

void    move_surface(t_surface *surf, int add_pos_x, int add_pos_y)
{
    surf->pos_x += add_pos_x;
    surf->pos_y = add_pos_y;
}