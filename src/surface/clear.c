#include "visual.h"

void    clear(t_surface *surf)
{
    for (int i = 0; i < surf->size; i++)
        surf->framebuffer[i] = TRANSPARENT;
}