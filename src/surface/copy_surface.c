#include "visual.h"

t_surface   *copy_surface(t_surface *surf)
{
    t_surface   *new;

    new = surface.create(surf->width, surf->height);
    if (!new)
        return (NULL);
    for (int y = 0; y < new->height; y++)
    {
        for (int x = 0; x < new->width; x++)
            put_pixel(new, x, y, get_pixel(surf, x, y));
    }
    //memcpy() would be better
    return (new);
}
