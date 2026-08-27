#include "visual.h"

void    draw_outlines(t_surface *surface,int size, uint32_t color)
{
    /*
        *draw functions does not create à surface, it simply change pixel(s) of an existent surface*
        -Draw outlines over a surface-
        This function take a pointer to the surface to drawn, the size (pixels) of the outlines and the color of the outlines;
        Example of call:
        draw_outlines(&image_1, 2, BLACK);
        (BLACK previously defined as 0xFF000000)
    */
    int     width;
    int     height;
    if (surface->size < 4)
        return;

    width = surface->width;
    height = surface->height;
    for (int i = 0; i < width * size; i++)
        surface->framebuffer[i] = color;
    for (int x = size; x < height; x++)
    {
        for (int y = 0; y < size; y++)
            surface->framebuffer[x * width + y] = color;
        for (int y = width - size; y < width; y++)
            surface->framebuffer[x * width + y] = color;
    }
    for (int i = width * height - width * size; i < surface->size ; i++)
        surface->framebuffer[i] = color;
}