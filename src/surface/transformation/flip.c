#include "visual.h"

static void horizontal_flip(t_surface *surf)
{
    int         p;
    int         p2;
    uint32_t    tmp_pixel;
    for (int y = 0; y < surf->height; y++)
    {
        for (int x = 0; x < surf->width / 2; x++)
        {
            p = y * surf->width + x;
            p2 = (y+1) * surf->width - 1 - x;
            tmp_pixel = surf->framebuffer[p];
            surf->framebuffer[p] = surf->framebuffer[p2];
            surf->framebuffer[p2] = tmp_pixel;         
        }
    }
}

static void vertical_flip(t_surface *surf)
{
    int         p;
    int         p2;
    uint32_t    tmp_pixel;
    for (int x = 0; x < surf->width; x++)
    {
        for (int y = 0; y < surf->height / 2; y++)
        {
            p = y * surf->width + x;
            p2 = (surf->height - 1 - y) * surf->width + x;
            tmp_pixel = surf->framebuffer[p];
            surf->framebuffer[p] = surf->framebuffer[p2];
            surf->framebuffer[p2] = tmp_pixel;         
        }
    }
}

void    flip(t_surface *surf, int way)
{
    if (way == HORIZONTAL)
        horizontal_flip(surf);
    else if (way == VERTICAL)
        vertical_flip(surf);
    else if (way == BOTH)
    {
        horizontal_flip(surf);
        vertical_flip(surf);
    }
    /*
    else
        error
    */
}