#include "visual.h"

void   crop_surface(t_surface *surf, t_point p1, t_point p2)
{
    int         min_x;
    int         max_x;
    int         min_y;
    int         max_y;
    int         new_width;
    int         new_height;
    uint32_t    pixel;
    uint32_t   *cropped;
    uint32_t    *tmp;

    min_x = min(p1.x, p2.x);
    max_x = max(p1.x, p2.x);
    min_y = min(p1.y, p2.y);
    max_y = max(p1.y, p2.y);
    new_width = absolute_value(p1.x - p2.x);
    new_height = absolute_value(p1.y - p2.y);
    cropped = malloc((size_t)(new_width) * new_height * sizeof(uint32_t));
    for (int y = min_y; y < max_y; y++)
    {
        for (int x = min_x; x < max_x; x++)
        {
            pixel = surf->framebuffer[y * surf->width + x];
            cropped[(y - min_y) * new_width +  (x - min_x)] = pixel;
        }
    }
    tmp = surf->framebuffer;
    surf->framebuffer = cropped;
    surf->width = new_width;
    surf->height = new_height;
    surf->size = new_width * new_height;
    free(tmp);
}