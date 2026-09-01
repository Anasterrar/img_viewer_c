#include "visual.h"

void    draw_square(t_surface *surface, int dimension, int pos_x, int pos_y, uint32_t color)
{
    /*
        *draw functions does not create à surface, it simply change pixel(s) of an existent surface*
        -Draw a square over a surface-
        This function take a pointer to the surface to draw, the dimension, the position and the color of the square;
        Example of call:
        draw_outlines(&image_1, 50, 0, 0, BLACK);
        (BLACK previously defined as 0xFF000000)
    */
    for (int y = pos_y; y < pos_y + dimension; y++)
    {
        for (int x = pos_x; x < pos_x + dimension; x++)
            surface->framebuffer[y * surface->width + x] = color;
    }
}