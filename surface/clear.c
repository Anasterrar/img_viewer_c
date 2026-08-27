#include "visual.h"

void    clear(t_surface *surface)
{
    for (int i = 0; i < surface->size; i++)
        surface->framebuffer[i] = TRANSPARENT;
}