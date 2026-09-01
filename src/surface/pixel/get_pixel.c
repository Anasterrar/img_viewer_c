#include "visual.h"

uint32_t    get_pixel(t_surface *surf, int pos_x, int pos_y)
{
    return (surf->framebuffer[pos_y * surf->width + pos_x]);
}