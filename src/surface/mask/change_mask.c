#include "visual.h"

void    change_mask(t_surface *surf, uint32_t color)
{
    uint32_t    pixel;
    for (int y = 0; y < surf->height; y++)
    {
        for (int x = 0; x < surf->width; x++)
        {
            pixel = surf->framebuffer[y * surf->width + x];
            if (pixel == surf->mask_color)
                put_pixel(surf, x, y, color);
        }
    }
    surface.put_mask(surf, color);
}