#include "visual.h"

t_surface   *create_outlines(t_surface *surf, int size, uint32_t color, int in_out)
{
    /*
        *create functions create a surface that can be destroyed (they are also automatically destroyed when quit())*
        -Create of surface with the same (+ size if OUT) size of the surface given, fill it with the outlines at the borders and transparent int the middle-
        This function take a pointer to the surface to replicate, the size (pixels) of the outlines and the color;
        Example of call:
        create_outlines(&image_1, 2, BLACK, INT);
        (BLACK previously defined as 0xFF000000)
        */
    int     width;
    int     height;
    t_surface   *outlines;

    width = surf->width + (size * in_out);
    height = surf->height + (size * in_out);
    outlines = surface.create(width, height);
    
    for (int i = 0; i < width * size; i++)
        outlines->framebuffer[i] = color;

    for (int x = size; x < height; x++)
    {
        for (int y = 0; y < width; y++)
        {
            if (y < size || y > width - size)
                outlines->framebuffer[x * width + y] = color;
            else
                outlines->framebuffer[x * width + y] = TRANSPARENT;
        }
    }
    for (int i = width * height - width * size; i < width * height ; i++)
        outlines->framebuffer[i] = color;

    return (outlines);
}