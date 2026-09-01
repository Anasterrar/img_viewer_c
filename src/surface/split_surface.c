#include "visual.h"

static bool         split_error_input(t_surface *surf, int x_y, int way)
{
    if (surf->width < 2 || surf->height < 2)
    {
        //error
        return (true);
    }
    if (way != HORIZONTAL && way != VERTICAL)
    {
        //error
        return (true);
    }
    if (way == HORIZONTAL && (x_y < 1 || x_y > surf->height - 2))
    {
        //error
        return (true);
    }
    if (way == VERTICAL && (x_y < 1 || x_y > surf->height - 2))
    {
        //error
        return (true);
    }
    return (false);
} 

static t_surface    *vertical_split(t_surface *surf, int s_x)
{
    int         width;
    int         height;
    t_surface   *new;
    
    width = surf->width - s_x;
    height = surf->height;
    new = surface.create(width, height);
    for (int y = 0; y < height; y++)
    {
        for (int x = s_x; x < surf->width; x++)
            put_pixel(new, x - s_x, y, get_pixel(surf, x, y));
    }
    surface.resize(surf, s_x, surf->height);
    return (new);
}

static t_surface    *horizontal_split(t_surface *surf, int s_y)
{
    int         width;
    int         height;
    t_surface   *new;
    
    width = surf->width;
    height = surf->height - s_y;
    new = surface.create(width, height);
    for (int y = s_y; y < surf->height; y++)
    {
        for (int x = 0; x < width; x++)
            put_pixel(new, x, y - s_y, get_pixel(surf, x, y));
    }
    surface.resize(surf, surf->width, s_y);
    return (new);
}

t_surface   *split(t_surface *surf, int split_x_y, int way)
{
    t_surface   *new;
    
    if (split_error_input(surf, split_x_y, way))
        return (NULL);
    if (way == VERTICAL)
        new = vertical_split(surf, split_x_y);
    if (way == HORIZONTAL)
        new = horizontal_split(surf, split_x_y);
    new->mask = surf->mask;
    new->mask_color = surf->mask_color;
    return (new);
}