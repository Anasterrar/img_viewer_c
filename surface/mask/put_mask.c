#include "visual.h"

void    put_mask(t_surface *surface, uint32_t color)
{
    surface->mask = true;
    surface->mask_color = color;
}