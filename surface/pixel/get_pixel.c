#include "visual.h"

uint32_t    get_pixel(t_surface *surface, int pos_x, int pos_y)
{
    return (surface->framebuffer[pos_y * surface->width + pos_x]);
}