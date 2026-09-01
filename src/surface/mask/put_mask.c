#include "visual.h"

void    put_mask(t_surface *surf, uint32_t color)
{
    surf->mask = true;
    surf->mask_color = color;
}